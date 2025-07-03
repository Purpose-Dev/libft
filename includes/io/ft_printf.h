/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 15:54:52 by smamalig          #+#    #+#             */
/*   Updated: 2025/06/01 12:16:12 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_PRINTF_H
# define LIBFT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

// Enjoy this very thread-safe printf :)

int	ft_printf(const char *fmt, ...)
	__attribute__((format (printf, 1, 2)));

int	ft_dprintf(int fd, const char *fmt, ...)
	__attribute__((format (printf, 2, 3)));

int	ft_sprintf(char *dst, const char *fmt, ...)
	__attribute__((format (printf, 2, 3)));

int	ft_snprintf(char *dst, size_t size, const char *fmt, ...)
	__attribute__((format (printf, 3, 4)));

// for internal use, you can also use them if you know what you're doing
// though why, if you can use the above alternatives?

int	ft_vprintf(const char *fmt, va_list ap);
int	ft_vdprintf(int fd, const char *fmt, va_list ap);
int	ft_vsprintf(char *dst, const char *fmt, va_list ap);
int	ft_vsnprintf(char *dst, size_t size, const char *fmt, va_list ap);

// not required as we won't use FILE structs
// int ft_fprintf(FILE *stream, const char *fmt, ...);
// int ft_vfprintf(FILE *stream, const char *fmt, va_list ap);

#endif
