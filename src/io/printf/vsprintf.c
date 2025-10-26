/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:42:14 by smamalig          #+#    #+#             */
/*   Updated: 2025/10/26 22:05:10 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

#include "io/ft_printf.h"

int	ft_vsprintf(char *dst, const char *fmt, va_list ap)
{
	return (ft_vsnprintf(dst, SIZE_MAX, fmt, ap));
}
