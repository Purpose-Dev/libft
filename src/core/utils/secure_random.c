/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secure_random.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 08:53:14 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/11 03:24:14 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/utils/secure_random.h"

static uint64_t	g_state[2] = {0x243f6a8885a308d3ULL, 0x13198a2e03707344ULL};

static uint64_t	rotl(const uint64_t x, const int k)
{
	return (x << k | x >> (64 - k));
}

void	ft_srand_secure(const uint64_t seed)
{
	if (seed == 0)
	{
		g_state[0] = 0x243f6a8885a308d3ULL;
		g_state[1] = 0x13198a2e03707344ULL;
	}
	else
	{
		g_state[0] = seed ^ 0x9e3779b97f4a7c15ULL;
		g_state[1] = seed;
	}
}

uint64_t	ft_rand_secure_u64(void)
{
	const uint64_t	s0 = g_state[0];
	const uint64_t	result = s0 * 0x9E3779B97F4A7C15ULL;
	uint64_t		s1;

	s1 = g_state[1];
	s1 ^= s0;
	g_state[0] = rotl(s0, 24) ^ s1 ^ (s1 << 16);
	g_state[1] = rotl(s1, 37);
	return (result);
}

uint32_t	ft_rand_secure_u32(void)
{
	return ((uint32_t)(ft_rand_secure_u64() >> 32));
}

int	ft_rand_secure_range(const int min, const int max)
{
	const int		range = max - min;

	if (min >= max)
		return (min);
	return (min + (int)(ft_rand_secure_u64() % (uint64_t)range));
}
