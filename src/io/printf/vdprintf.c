/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vdprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:45:24 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/13 16:59:25 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_printf.h"
#include <unistd.h>

#define BUFFER_SIZE 1024

#ifdef _WIN32

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	auto char small_buf[BUFFER_SIZE];
	auto va_list ap_copy;
	va_copy(ap_copy, ap);
	auto int len = ft_vsnprintf(NULL, 0, fmt, ap_copy);
	if (len < 0)
		return (len);
	va_end(ap_copy);
	auto char *buf = small_buf;
	if (len >= BUFFER_SIZE)
	{
		buf = malloc((size_t)(len + 1));
		if (!buf)
			return (-1);
	}
	len = ft_vsnprintf(buf, (size_t)(len + 1), fmt, ap);
	_write(fd, buf, (size_t)len);
	if (buf != small_buf)
		free(buf);
	return (len);
}
#else

int	ft_vdprintf(int fd, const char *fmt, va_list ap)
{
	auto char small_buf[BUFFER_SIZE];
	auto va_list ap_copy;
	va_copy(ap_copy, ap);
	auto int len = ft_vsnprintf(NULL, 0, fmt, ap_copy);
	if (len < 0)
		return (len);
	va_end(ap_copy);
	auto char *buf = small_buf;
	if (len >= BUFFER_SIZE)
	{
		buf = malloc((size_t)(len + 1));
		if (!buf)
			return (-1);
	}
	len = ft_vsnprintf(buf, (size_t)(len + 1), fmt, ap);
	write(fd, buf, (size_t)len);
	if (buf != small_buf)
		free(buf);
	return (len);
}
#endif
