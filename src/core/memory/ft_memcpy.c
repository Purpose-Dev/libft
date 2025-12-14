/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 21:48:13 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/12/14 22:27:45 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <immintrin.h>

#include "core/memory/ft_memory.h"

static void	*fallback_memcpy(void *dest, const void *src, const size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	size_t				i;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*s;
	unsigned char		*d;
	__m256i				data;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	while (n > 0 && ((uintptr_t)d & 31))
	{
		*d++ = *s++;
		n--;
	}
	while (n >= 32)
	{
		data = _mm256_loadu_si256((const __m256i *)(uintptr_t)s);
		_mm256_stream_si256((__m256i *)(uintptr_t)d, data);
		d += 32;
		s += 32;
		n -= 32;
	}
	if (n > 0)
		fallback_memcpy(d, s, n);
	_mm_sfence();
	return (dest);
}
