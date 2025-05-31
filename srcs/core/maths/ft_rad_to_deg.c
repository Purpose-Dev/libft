/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rad_to_deg.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:41:24 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/31 23:02:11 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

double	ft_rad_to_deg(double radians)
{
	if (ft_is_nan(radians))
		return (NAN);
	else if (ft_is_inf(radians))
	{
		if (radians < 0.0)
			return (-INFINITY);
		return (INFINITY);
	}
	return (radians * 180.0 / PI);
}
