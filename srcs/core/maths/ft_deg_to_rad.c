/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deg_to_rad.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:40:01 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/31 18:48:00 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/ft_maths.h"

double	ft_deg_to_rad(double degrees)
{
	if (ft_is_nan(degrees))
		return (NAN);
	else if (ft_is_inf(degrees))
	{
		if (degrees < 0.0)
			return (-INFINITY);
		return (INFINITY);
	}
	return (degrees * PI / 180.0);
}
