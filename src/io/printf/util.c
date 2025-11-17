/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 23:51:08 by smamalig          #+#    #+#             */
/*   Updated: 2025/11/17 14:16:11 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_printf_internal.h"

int	__ft_printf_int_len(intmax_t n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

int	__ft_printf_uint_len(uintmax_t n)
{
	int	len;

	len = 0;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

intmax_t	__ft_printf_abs(intmax_t n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char	__ft_printf_abs_char(char c)
{
	if (c < 0)
		return ((char)-c);
	return (c);
}

void	__ft_printf_char(t_printf_parser *p, char c)
{
	__ft_printf_padding(p, 1, PRINTF_START, PRINTF_OTHER);
	__ft_printf_insert(p, c);
	__ft_printf_padding(p, 1, PRINTF_END, PRINTF_OTHER);
}
