/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 04:17:32 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 14:09:02 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

double	ft_pow(double base, const int exp)
{
	double	result;
	int		abs_exp;

	if (exp == 0)
		return (1.0);
	if (base == 0.0)
		return (0.0);
	result = 1.0;
	abs_exp = ft_abs(exp);
	while (abs_exp > 0)
	{
		if (abs_exp & 1)
			result *= base;
		base *= base;
		abs_exp /= 2;
	}
	if (exp < 0)
		return (1.0 / result);
	return (result);
}
