/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:52:25 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 13:57:34 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

double	ft_floor(const double x)
{
	double	truncated_x;

	if (ft_is_nan(x) || ft_is_inf(x))
		return (x);
	if (x >= 0.0)
		return ((double)((long long)x));
	truncated_x = (double)((long long)x);
	if (truncated_x > x)
		return (truncated_x - 1.0);
	return (truncated_x);
}
