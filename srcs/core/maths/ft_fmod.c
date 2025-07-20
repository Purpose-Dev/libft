/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fmod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 08:44:08 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 14:30:20 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <float.h>
#include "core/maths/ft_maths.h"

double	ft_fmod(const double x, const double y)
{
	double	quotient;
	double	n;

	if (y == 0.0)
		return (errno = EDOM, (double)NAN);
	if (ft_is_nan(x) || ft_is_nan(y))
		return ((double)NAN);
	if (ft_is_inf(x))
	{
		if (ft_is_inf(y))
			return (errno = EDOM, (double)NAN);
		return (errno = EDOM, (double)NAN);
	}
	if (ft_is_inf(y))
		return (x);
	if (x == 0.0)
		return (0.0);
	quotient = x / y;
	n = ft_trunc(quotient);
	return (x - n * y);
}
