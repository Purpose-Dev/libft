/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_multiple.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 02:20:20 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/18 11:49:27 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string/ft_string.h"

static size_t	calculate_total_length(const int count, va_list *args)
{
	size_t	total_len;
	char	*str;
	int		i;

	total_len = 0;
	i = 0;
	while (i < count)
	{
		str = va_arg(*args, char *);
		if (str)
			total_len += ft_strlen(str);
		i++;
	}
	return (total_len);
}

static char	*copy_strings(char *result, const int count, va_list *args)
{
	char	*str;
	size_t	pos;
	size_t	len;
	int		i;

	pos = 0;
	i = 0;
	while (i < count)
	{
		str = va_arg(*args, char *);
		if (str)
		{
			len = ft_strlen(str);
			ft_strlcpy(result + pos, str, len + 1);
			pos += len;
		}
		i++;
	}
	result[pos] = '\0';
	return (result);
}

char	*ft_strjoin_multiple(const int count, ...)
{
	va_list	args;
	va_list	args_copy;
	size_t	total_len;
	char	*result;

	if (count <= 0)
		return (ft_strdup(""));
	va_start(args, count);
	va_copy(args_copy, args);
	total_len = calculate_total_length(count, &args);
	va_end(args);
	result = malloc(sizeof(char) * (total_len + 1));
	if (!result)
	{
		va_end(args_copy);
		return (NULL);
	}
	copy_strings(result, count, &args_copy);
	va_end(args_copy);
	return (result);
}
