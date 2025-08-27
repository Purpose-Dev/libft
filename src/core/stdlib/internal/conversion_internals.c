/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_internals.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 04:22:55 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/08/27 04:28:07 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
