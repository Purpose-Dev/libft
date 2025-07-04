/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:51:57 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/04 01:53:24 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string/ft_string.h"

static char	*add_integer_part(char *str, const long int_part, int *pos)
{
	auto char *int_str = ft_ltoa(int_part);
	if (!int_str)
		return (NULL);
	auto int i = 0;
	while (int_str[i])
	{
		str[*pos] = int_str[i];
		(*pos)++;
		i++;
	}
	free(int_str);
	return (str);
}

char	*ft_ftoa(const double f, const int precision)
{
	auto char *str = (char *)malloc(64);
	if (!str)
		return (NULL);
	auto int pos = 0;
	auto const long int_part = (long)f;
	auto double frac_part = f - (double)int_part;
	if (!add_integer_part(str, int_part, &pos))
		return (free(str), NULL);
	if (precision > 0)
	{
		str[pos++] = '.';
		auto int i = 0;
		while (i < precision)
		{
			frac_part *= 10;
			str[pos++] = (char)(frac_part + '0');
			frac_part -= (int)frac_part;
			i++;
		}
	}
	str[pos] = '\0';
	return (str);
}
