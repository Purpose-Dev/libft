/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:52:45 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/02 06:59:51 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

double	ft_round(const double x)
{
	int		sign;
	double	abs_x;
	double	fractional_part;

	if (ft_is_nan(x) || ft_is_inf(x))
		return (x);
	if (x < 0.0)
		sign = -1;
	else
		sign = 1;
	if (sign == -1)
		abs_x = -x;
	else
		abs_x = x;
	fractional_part = abs_x - ft_floor(abs_x);
	if (fractional_part >= 0.5)
		return (sign * ft_floor(abs_x + 0.5));
	return (sign * ft_floor(abs_x));
}
