/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rad_to_deg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:41:24 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 14:07:06 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

double	ft_rad_to_deg(double radians)
{
	if (ft_is_nan(radians))
		return ((double)NAN);
	else if (ft_is_inf(radians))
	{
		if (radians < 0.0)
			return (-(double)INFINITY);
		return ((double)INFINITY);
	}
	return (radians * 180.0 / PI);
}
