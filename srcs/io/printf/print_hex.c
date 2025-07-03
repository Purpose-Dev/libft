/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:34:46 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/03 20:24:14 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_printf_internal.h"

static void	__ft_printf_hex_internal(t_printf_parser *p, uintmax_t n,
	int mask, int iters)
{
	if (!iters)
		return ;
	__ft_printf_hex_internal(p, n >> 4, mask, iters - 1);
	__ft_printf_insert(p, (char)("0123456789ABCDEF"[n & 0xF] | mask));
}

static int	__ft_printf_print_len(t_printf_parser *parser, uintmax_t n)
{
	int	len;

	len = 0;
	if (n == 0 && parser->prec == -1)
		return (1);
	while (n)
	{
		n >>= 4;
		len++;
	}
	if (parser->prec > len)
		return (parser->prec);
	return (len);
}

static int	__ft_printf_0x(t_printf_parser *p, int start, int mask)
{
	if (!(p->flags & PRINTF_FLAG_ALTERNATE))
		return (0);
	if (start && !(p->flags & PRINTF_FLAG_ZEROPAD))
		return (0);
	if (!start && p->flags & PRINTF_FLAG_ZEROPAD)
		return (0);
	__ft_printf_insert(p, '0');
	__ft_printf_insert(p, (char)('X' | mask));
	return (2);
}

void	__ft_printf_hex(t_printf_parser *p, uintmax_t n, int mask)
{
	const int	len = __ft_printf_print_len(p, n);
	const int	off = ((p->flags & PRINTF_FLAG_ALTERNATE) > 0) << 1;

	if (p->prec >= 0)
		p->flags &= ~PRINTF_FLAG_ZEROPAD;
	if (n != 0)
		__ft_printf_0x(p, PRINTF_START, mask);
	__ft_printf_padding(p, len + off, PRINTF_START, PRINTF_NUMERIC);
	if (n != 0)
		__ft_printf_0x(p, PRINTF_END, mask);
	__ft_printf_hex_internal(p, n, mask, len);
	__ft_printf_padding(p, len + off, PRINTF_END, PRINTF_NUMERIC);
}

void	__ft_printf_pointer(t_printf_parser *p, const void *ptr)
{
	if (!ptr)
	{
		__ft_printf_str(p, "(nil)");
		return ;
	}
	p->flags |= PRINTF_FLAG_ALTERNATE;
	__ft_printf_hex(p, (size_t)ptr, 0x20);
}
