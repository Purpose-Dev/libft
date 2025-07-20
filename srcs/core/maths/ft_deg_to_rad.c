/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deg_to_rad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:40:01 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 14:06:10 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

double	ft_deg_to_rad(double degrees)
{
	if (ft_is_nan(degrees))
		return ((double)NAN);
	else if (ft_is_inf(degrees))
	{
		if (degrees < 0.0)
			return (-(double)INFINITY);
		return ((double)INFINITY);
	}
	return (degrees * PI / 180.0);
}
