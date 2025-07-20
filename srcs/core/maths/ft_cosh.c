/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cosh.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:54:55 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 14:08:04 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

double	ft_cosh(const double x)
{
	double	exp_pos;
	double	exp_neg;

	if (ft_is_nan(x))
		return (x);
	if (ft_is_inf(x))
		return ((double)INFINITY);
	if (x > 700 || x < -700)
	{
		errno = ERANGE;
		return ((double)INFINITY);
	}
	exp_pos = exp(x);
	exp_neg = exp(-x);
	return ((exp_pos + exp_neg) / 2.0);
}
