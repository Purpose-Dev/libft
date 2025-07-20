/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 17:38:05 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 14:26:22 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/maths/ft_maths.h"

double	ft_sqrt(const double x)
{
	double	guess;
	double	prev_guess;
	double	epsilon;
	int		iterations;

	if (x < 0.0)
		return (-1.0);
	if (x == 0.0 || x == 1.0)
		return (x);
	if (x < 1.0)
		guess = x;
	else
		guess = x / 2.0;
	epsilon = 1e-15;
	iterations = 0;
	while (iterations < 50)
	{
		prev_guess = guess;
		guess = (guess + x / guess) * 0.5;
		if (ft_fabs(guess - prev_guess) < epsilon)
			break ;
		iterations++;
	}
	return (guess);
}
