/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vsprintf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 16:42:14 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/03 20:26:36 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_printf.h"
#include <stdint.h>

int	ft_vsprintf(char *dst, const char *fmt, va_list ap)
{
	return (ft_vsnprintf(dst, SIZE_MAX, fmt, ap));
}
