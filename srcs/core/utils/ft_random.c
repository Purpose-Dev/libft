/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/01 11:10:32 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/02 05:47:26 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/utils/ft_random.h"
#include "core/maths/ft_maths.h"

unsigned long int	g_ft_rand_next = 1;

void	ft_srand(const unsigned int seed)
{
	if (seed == 0)
		g_ft_rand_next = 1lu;
	else
		g_ft_rand_next = seed;
}

int	ft_rand(void)
{
	g_ft_rand_next = g_ft_rand_next * FT_RAND_A + FT_RAND_C;
	return ((int)(g_ft_rand_next % (FT_RAND_MAX + 1)));
}

double	ft_randf(void)
{
	return ((double) ft_rand() / (FT_RAND_MAX + 1.0));
}

int	ft_rand_range(int min, int max)
{
	long long	range_size;

	if (min > max)
		ft_swap(&min, &max);
	range_size = (long long) max - min + 1;
	if (range_size <= 0)
		return (min);
	return (min + (ft_rand() % (int)range_size));
}
