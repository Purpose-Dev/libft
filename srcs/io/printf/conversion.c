/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 20:09:02 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/18 11:47:09 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_printf_internal.h"
#include "core/string/ft_string.h"

#include <limits.h>

static int	__ft_printf_set_mod(t_printf_parser *p, const char *s, int mod)
{
	int	i;

	i = 0;
	while (s[i] && p->fmt[i] == s[i])
		i++;
	if (s[i] == '\0')
	{
		p->len_mod = mod;
		p->fmt += i;
	}
	return (0);
}

static void	__ft_printf_len_mod(t_printf_parser *p)
{
	if (__ft_printf_set_mod(p, "hh", PRINTF_LEN_HH))
		return ;
	if (__ft_printf_set_mod(p, "ll", PRINTF_LEN_LL))
		return ;
	if (__ft_printf_set_mod(p, "L", PRINTF_LEN_LL))
		return ;
	if (__ft_printf_set_mod(p, "q", PRINTF_LEN_LL))
		return ;
	if (__ft_printf_set_mod(p, "h", PRINTF_LEN_H))
		return ;
	if (__ft_printf_set_mod(p, "l", PRINTF_LEN_L))
		return ;
	if (__ft_printf_set_mod(p, "j", PRINTF_LEN_J))
		return ;
	if (__ft_printf_set_mod(p, "z", PRINTF_LEN_Z))
		return ;
	if (__ft_printf_set_mod(p, "Z", PRINTF_LEN_Z))
		return ;
	if (__ft_printf_set_mod(p, "t", PRINTF_LEN_T))
		return ;
}

#ifdef USE_ERRNO

static void	__ft_printf_conversion(t_printf_parser *p)
{
	if (p->match(p, 'n'))
		__ft_printf_save_pos(p, va_arg(p->ap, void *));
	else if (p->match(p, 's'))
		__ft_printf_str(p, va_arg(p->ap, const char *));
	else if (p->match(p, '%'))
		__ft_printf_insert(p, '%');
	else if (p->match(p, 'c'))
		__ft_printf_char(p, va_arg(p->ap, int));
	else if (p->match(p, 'i') || p->match(p, 'd'))
		__ft_printf_handle_int(p);
	else if (p->match(p, 'u'))
		__ft_printf_handle_uint(p);
	else if (p->match(p, 'm'))
		__ft_printf_strerror(p);
	else if (p->match(p, 'p'))
		__ft_printf_pointer(p, va_arg(p->ap, const void *));
	else if (p->match(p, 'x'))
		__ft_printf_handle_hex(p, 0x20);
	else if (p->match(p, 'X'))
		__ft_printf_handle_hex(p, 0);
	else
		__ft_printf_invalid_format(p);
}

#else

static void	__ft_printf_conversion(t_printf_parser *p)
{
	if (p->match(p, 'n'))
		__ft_printf_save_pos(p, va_arg(p->ap, void *));
	else if (p->match(p, 's'))
		__ft_printf_str(p, va_arg(p->ap, const char *));
	else if (p->match(p, '%'))
		__ft_printf_insert(p, '%');
	else if (p->match(p, 'c'))
		__ft_printf_char(p, (char)va_arg(p->ap, int));
	else if (p->match(p, 'i') || p->match(p, 'd'))
		__ft_printf_handle_int(p);
	else if (p->match(p, 'u'))
		__ft_printf_handle_uint(p);
	else if (p->match(p, 'p'))
		__ft_printf_pointer(p, va_arg(p->ap, const void *));
	else if (p->match(p, 'x'))
		__ft_printf_handle_hex(p, 0x20);
	else if (p->match(p, 'X'))
		__ft_printf_handle_hex(p, 0);
	else
		__ft_printf_invalid_format(p);
}

#endif

int	__ft_printf_handle_conv(t_printf_parser *p)
{
	while (ft_strchr("#0- +", p->curr(p)))
		__ft_printf_parse_flags(p);
	if (__ft_printf_parse_width(p))
		return (1);
	if (p->match(p, '.') && __ft_printf_parse_precision(p))
		return (1);
	__ft_printf_len_mod(p);
	__ft_printf_conversion(p);
	return (0);
}
