/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:15:44 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/03 20:11:37 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_printf_internal.h"

void	__ft_printf_save_pos(t_printf_parser *p, void *save_ptr)
{
	if (p->len_mod == PRINTF_LEN_HH)
		*(signed char *)save_ptr = (signed char)p->pos;
	else if (p->len_mod == PRINTF_LEN_H)
		*(short *)save_ptr = (short)p->pos;
	else if (p->len_mod == PRINTF_LEN_L)
		*(long *)save_ptr = (long)p->pos;
	else if (p->len_mod == PRINTF_LEN_LL)
		*(long long *)save_ptr = (long long)p->pos;
	else if (p->len_mod == PRINTF_LEN_J)
		*(intmax_t *)save_ptr = (intmax_t)p->pos;
	else if (p->len_mod == PRINTF_LEN_Z)
		*(size_t *)save_ptr = p->pos;
	else if (p->len_mod == PRINTF_LEN_T)
		*(ptrdiff_t *)save_ptr = (ptrdiff_t)p->pos;
	else
		*(int *)save_ptr = (int)p->pos;
}
