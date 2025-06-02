/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_double_equals.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:55:25 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/01 03:56:15 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

int	ft_double_equals(const double a, const double b, double epsilon)
{
	if (ft_is_nan(a) || ft_is_nan(b))
		return (0);
	if (ft_is_inf(a) && ft_is_inf(b))
	{
		if (a == b)
			return (1);
		return (0);
	}
	if (epsilon <= 0.0)
		epsilon = 1e-15;
	if (ft_fabs(a - b) < epsilon)
		return (1);
	return (0);
}
