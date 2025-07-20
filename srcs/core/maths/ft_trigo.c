/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trigo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:54:38 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 14:07:39 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

static double	ft_trigo_check(const double x)
{
	if (ft_is_nan(x))
		return (x);
	if (ft_is_inf(x))
		return (errno = EDOM, (double)NAN);
	return (0.0);
}

double	ft_cos(const double x)
{
	double	term;
	double	sum;
	double	x_squared;
	int		n;
	double	current_x;

	current_x = ft_trigo_check(x);
	if (ft_is_nan(current_x) || ft_is_inf(current_x))
		return (current_x);
	current_x = ft_fmod(x, 2.0 * PI);
	if (current_x > PI)
		current_x -= 2.0 * PI;
	else if (current_x < -PI)
		current_x += 2.0 * PI;
	term = 1.0;
	sum = term;
	x_squared = current_x * current_x;
	n = 1;
	while (ft_fabs(term) > DBL_EPSILON)
	{
		term = -term * x_squared / ((2 * n - 1) * (2 * n));
		sum += term;
		n++;
	}
	return (sum);
}

double	ft_sin(const double x)
{
	double	term;
	double	sum;
	double	x_squared;
	int		n;
	double	current_x;

	current_x = ft_trigo_check(x);
	if (ft_is_nan(current_x) || ft_is_inf(current_x))
		return (current_x);
	current_x = ft_fmod(x, 2.0 * PI);
	if (current_x > PI)
		current_x -= 2.0 * PI;
	else if (current_x < PI)
		current_x += 2.0 * PI;
	term = current_x;
	sum = term;
	x_squared = current_x * current_x;
	n = 1;
	while (ft_fabs(term) > DBL_EPSILON)
	{
		term = -term * x_squared / ((2 * n) * (2 * n + 1));
		sum += term;
		n++;
	}
	return (sum);
}

double	ft_tan(const double x)
{
	double	cos_x;
	double	sin_x;

	(void)ft_trigo_check(x);
	cos_x = ft_cos(x);
	sin_x = ft_sin(x);
	if (ft_double_equals(cos_x, 0.0, 1e-9))
	{
		errno = ERANGE;
		return (sin_x / cos_x);
	}
	return (sin_x / cos_x);
}
