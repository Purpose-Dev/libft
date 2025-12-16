/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 16:55:50 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/12/16 18:02:37 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <emmintrin.h>
#include <stdint.h>

#include "core/string/ft_string.h"

size_t	ft_strlen(const char *s)
{
	const char		*char_ptr = s;
	const __m128i	zero_vec = _mm_setzero_si128();
	__m128i			data_vec;
	__m128i			result;
	int				mask;

	while (((uintptr_t)char_ptr & 0xF) != 0)
	{
		if (*char_ptr == 0)
			return ((size_t)(char_ptr - s));
		char_ptr++;
	}
	while (1)
	{
		data_vec = _mm_load_si128((const __m128i *)(uintptr_t)char_ptr);
		result = _mm_cmpeq_epi8(data_vec, zero_vec);
		mask = _mm_movemask_epi8(result);
		if (mask != 0)
			return ((size_t)((char_ptr - s) + __builtin_ctz((uint32_t)mask)));
		char_ptr += 16;
	}
}
