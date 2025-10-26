/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:40:06 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/10/26 19:41:44 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_printf.h"

int	ft_fprintf(t_ft_file *stream, const char *fmt, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, fmt);
	ret = ft_vfprintf(stream, fmt, ap);
	va_end(ap);
	return (ret);
}
