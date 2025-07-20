/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sinh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:54:52 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 14:00:01 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

double	ft_sinh(const double x)
{
	double	exp_pos;
	double	exp_neg;

	if (ft_is_nan(x))
		return (x);
	if (ft_is_inf(x))
		return (x);
	if (x > 700)
	{
		errno = ERANGE;
		return ((double)INFINITY);
	}
	if (x < -700)
	{
		errno = ERANGE;
		return (-(double)INFINITY);
	}
	exp_pos = exp(x);
	exp_neg = exp(-x);
	return ((exp_pos - exp_neg) / 2.0);
}
