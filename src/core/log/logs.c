/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:07:43 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/11/17 14:39:50 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

#include "core/log/log.h"

void	log_debug(const char *module, const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	ft_vlog(LOG_DEBUG, module, format, args);
	va_end(args);
}

void	log_error(const char *module, const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	ft_vlog(LOG_ERROR, module, format, args);
	va_end(args);
}

void	log_fatal(const char *module, const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	ft_vlog(LOG_FATAL, module, format, args);
	va_end(args);
}

void	log_info(const char *module, const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	ft_vlog(LOG_INFO, module, format, args);
	va_end(args);
}

void	log_warn(const char *module, const char *format, ...)
{
	va_list	args;

	va_start(args, format);
	ft_vlog(LOG_WARN, module, format, args);
	va_end(args);
}
