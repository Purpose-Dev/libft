/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_fnv1a_hash.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 07:56:43 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 07:58:40 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"

uint32_t	hashmap_fnv1a_hash(const char *key)
{
	uint32_t	hash;
	uint32_t	i;

	if (!key)
		return (0);
	hash = 2166136261U;
	i = 0;
	while (key[i])
	{
		hash ^= (unsigned char)key[i];
		hash *= 16777619U;
		i++;
	}
	return (hash);
}
