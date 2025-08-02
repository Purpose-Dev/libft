/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_nan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:55:50 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/02 07:11:30 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

int	ft_is_nan(const double x)
{
	t_double_caster	caster;

	caster.d = x;
	if (((caster.ull & EXPONENT_MASK) >> 52) == 0x7FFULL
		&& (caster.ull & MANTISSA_MASK) != 0ULL)
		return (1);
	return (0);
}
