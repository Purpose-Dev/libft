/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_internals.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 04:22:55 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/17 19:17:45 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/ctype/ft_ctype.h"
#include "core/stdlib/ft_stdlib_internal.h"

int	ft_is_valid_base(const int c, const int base)
{
	if (base <= 10)
		return (c >= '0' && c < '0' + base);
	return ((c >= '0' && c <= '9')
		|| (c >= 'a' && c < 'a' + base - 10)
		|| (c >= 'A' && c < 'A' + base - 10));
}

int	ft_char_to_digit(const int c, const int base)
{
	int	digit;

	if (c >= '0' && c <= '9')
		digit = c - '0';
	else if (c >= 'a' && c <= 'z')
		digit = c - 'a' + 10;
	else if (c >= 'A' && c <= 'Z')
		digit = c - 'A' + 10;
	else
		return (-1);
	if (digit >= base)
		return (-1);
	return (digit);
}

int	ft_parse_sign(const char **nptr)
{
	int	sign;

	sign = 1;
	if (**nptr == '-' || **nptr == '+')
	{
		if (**nptr == '-')
			sign = -1;
		(*nptr)++;
	}
	return (sign);
}

const char	*ft_skip_whitespace(const char *nptr)
{
	while (ft_isspace((unsigned char)*nptr))
		nptr++;
	return (nptr);
}

int	ft_detect_base(const char **nptr, const int base)
{
	if (base == 0)
	{
		if (**nptr == '0')
		{
			if (*(*nptr + 1) == 'x' || *(*nptr + 1) == 'X')
			{
				*nptr += 2;
				return (16);
			}
			(*nptr)++;
			return (8);
		}
		return (10);
	}
	if (base == 16 && **nptr == '0'
		&& (*(*nptr + 1) == 'x' || *(*nptr + 1) == 'X'))
		*nptr += 2;
	return (base);
}
