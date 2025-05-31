/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:55:41 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/31 23:01:01 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

static double	ft_abs_double(const double x)
{
	if (x < 0.0)
		return (-x);
	return (x);
}

int	ft_is_zero(double x)
{
	const double	epsilon = 1e-15;

	if (ft_is_nan(x))
		return (0);
	return (ft_abs_double(x) < epsilon);
}
