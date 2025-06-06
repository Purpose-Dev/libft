/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clampf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:51:33 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/06 22:57:23 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

double	ft_clampf(const double value, const double min, const double max)
{
	if (ft_is_nan(value) || ft_is_nan(min) || ft_is_nan(max))
		return (NAN);
	if (min <= max)
	{
		if (value < min)
			return (min);
		if (value > max)
			return (max);
		return (value);
	}
	return (max);
}
