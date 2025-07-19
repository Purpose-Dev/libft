/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fgets.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:57:34 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/19 06:08:06 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_io.h"

char	*ft_fgets(char *str, const int size, t_ft_file *stream)
{
	if (!str || size <= 0 || !stream)
		return (NULL);
	if (size == 1)
	{
		str[0] = '\0';
		return (str);
	}
	auto int i = 0;
	while (i < size - 1)
	{
		auto int c = ft_getc(stream);
		if (c == FT_EOF)
		{
			if (i == 0)
				return (NULL);
			break ;
		}
		str[i] = (char)c;
		i++;
		if (c == '\n')
			break ;
	}
	str[i] = '\0';
	return (str);
}
