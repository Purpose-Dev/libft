/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:30:25 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/03 20:09:56 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_printf.h"

int	ft_sprintf(char *dst, const char *fmt, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, fmt);
	len = ft_vsprintf(dst, fmt, ap);
	va_end(ap);
	return (len);
}
