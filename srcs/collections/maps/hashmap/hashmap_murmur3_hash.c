/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_murmur3_hash.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 07:44:52 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 07:56:21 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../../includes/collections/maps/hashmap/ft_hashmap.h"
#include "../../../../includes/core/string/ft_string.h"

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_murmur3_hash.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 07:44:52 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 07:52:15 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"
#include "core/string/ft_string.h"

static uint32_t	murmur3_scramble(uint32_t k)
{
	k *= 0xCC9E2D51;
	k = (k << 15) | (k >> 17);
	k *= 0x1B873593;
	return (k);
}

static uint32_t	murmur3_eoh(uint32_t hash, const uint32_t k, const size_t len)
{
	hash ^= murmur3_scramble(k);
	hash ^= len;
	hash ^= hash >> 16;
	hash *= 0x85EBCA6B;
	hash ^= hash >> 13;
	hash *= 0xC2B2AE35;
	hash ^= hash >> 16;
	return (hash);
}

static uint32_t	process_main_blocks(const char *key, const size_t len)
{
	uint32_t	hash;
	uint32_t	k;
	size_t		i;

	hash = 1234567890U;
	i = 0;
	while (i + 4 <= len)
	{
		k = ((uint32_t)key[i]) | ((uint32_t)key[i + 1] << 8)
			| ((uint32_t)key[i + 2] << 16) | ((uint32_t)key[i + 3] << 24);
		hash ^= murmur3_scramble(k);
		hash = (hash << 13) | (hash >> 19);
		hash = hash * 5 + 0xE6546B64;
		i += 4;
	}
	return (hash);
}

static uint32_t	process_remaining_bytes(const char *key, const size_t len,
										const size_t start)
{
	uint32_t	k;
	size_t		i;

	k = 0;
	i = start;
	while (i < len)
	{
		k |= ((uint32_t)key[i]) << ((i % 4) * 8);
		i++;
	}
	return (k);
}

uint32_t	hashmap_murmur3_hash(const char *key)
{
	uint32_t	hash;
	uint32_t	k;
	size_t		len;
	size_t		main_blocks_end;

	if (!key)
		return (0);
	len = ft_strlen(key);
	hash = process_main_blocks(key, len);
	main_blocks_end = (len / 4) * 4;
	k = process_remaining_bytes(key, len, main_blocks_end);
	return (murmur3_eoh(hash, k, len));
}
