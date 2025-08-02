/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 05:52:09 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 06:05:17 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"

void	*hashmap_get(t_hashmap *map, const char *key)
{
	uint32_t		hash;
	size_t			index;
	t_hashmap_entry	*entry;

	if (!map || !key)
		return (NULL);
	hash = map->hash_func(key);
	index = hash % map->capacity;
	entry = map->buckets[index];
	while (entry)
	{
		if (entry->hash == hash && map->key_cmp(entry->key, key) == 0)
			return (entry->value);
		entry = entry->next;
	}
	return (NULL);
}
