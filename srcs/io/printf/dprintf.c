/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:29:35 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/03 20:09:46 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_printf.h"

int	ft_dprintf(int fd, const char *fmt, ...)
{
	va_list	ap;
	int		len;

	va_start(ap, fmt);
	len = ft_vdprintf(fd, fmt, ap);
	va_end(ap);
	return (len);
}
