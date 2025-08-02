/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 15:13:55 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/03 20:08:59 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_printf_internal.h"

void	__ft_printf_insert(t_printf_parser *parser, char c)
{
	if (parser->pos < parser->size)
		parser->dst[parser->pos] = c;
	else if (parser->pos == parser->size - 1)
		parser->dst[parser->pos] = 0;
	parser->pos++;
}

void	__ft_printf_padding(t_printf_parser *parser, int len, int is_start,
	int is_numeric)
{
	if (len < 0)
		return ;
	if (is_start && parser->flags & PRINTF_FLAG_LEFTADJ)
		return ;
	if (is_start && is_numeric && parser->flags & PRINTF_FLAG_ZEROPAD)
		while (parser->width-- - len > 0)
			__ft_printf_insert(parser, '0');
	else
		while (parser->width-- - len > 0)
			__ft_printf_insert(parser, ' ');
}

void	__ft_printf_sign(t_printf_parser *parser, int is_neg, int start)
{
	if (start && !(parser->flags & PRINTF_FLAG_ZEROPAD))
		return ;
	if (!start && parser->flags & PRINTF_FLAG_ZEROPAD)
		return ;
	if (is_neg)
		__ft_printf_insert(parser, '-');
	else if (parser->flags & PRINTF_FLAG_SIGN)
		__ft_printf_insert(parser, '+');
	else if (parser->flags & PRINTF_FLAG_SPPAD)
		__ft_printf_insert(parser, ' ');
}

int	__ft_printf_parse_flags(t_printf_parser *p)
{
	if (*p->fmt == '#')
		p->flags |= PRINTF_FLAG_ALTERNATE;
	else if (*p->fmt == '0')
		p->flags |= PRINTF_FLAG_ZEROPAD;
	else if (*p->fmt == '-')
		p->flags |= PRINTF_FLAG_LEFTADJ;
	else if (*p->fmt == ' ')
		p->flags |= PRINTF_FLAG_SPPAD;
	else
		p->flags |= PRINTF_FLAG_SIGN;
	p->next(p);
	return (0);
}
