/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:40:57 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/03 20:26:53 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_printf_internal.h"

static void	__ft_printf_uint_internal(t_printf_parser *parser,
	uintmax_t n, int iters)
{
	if (!iters)
		return ;
	__ft_printf_uint_internal(parser, n / 10, iters - 1);
	__ft_printf_insert(parser, n % 10 + '0');
}

static int	__ft_printf_print_len(t_printf_parser *parser, uintmax_t n)
{
	const int	len = __ft_printf_uint_len(n);

	if (n == 0 && parser->prec == -1)
		return (1);
	if (parser->prec > len)
		return (parser->prec);
	return (len);
}

void	__ft_printf_uint(t_printf_parser *parser, uintmax_t n)
{
	const int	len = __ft_printf_print_len(parser, n);

	if (parser->prec >= 0)
		parser->flags &= ~PRINTF_FLAG_ZEROPAD;
	__ft_printf_padding(parser, len, PRINTF_START, PRINTF_NUMERIC);
	__ft_printf_uint_internal(parser, n, len);
	__ft_printf_padding(parser, len, PRINTF_END, PRINTF_NUMERIC);
}
