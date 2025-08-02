/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:33:13 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/03 20:11:57 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_printf.h"

int	ft_snprintf(char *dst, size_t size, const char *fmt, ...)
{
	va_list	ap;	
	int		len;

	va_start(ap, fmt);
	len = ft_vsnprintf(dst, size, fmt, ap);
	va_end(ap);
	return (len);
}
