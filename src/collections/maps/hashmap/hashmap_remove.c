/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 05:52:19 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 06:12:48 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"

static void	*hashmap_remove_entry(t_hashmap *map, const size_t index,
									t_hashmap_entry *entry,
									t_hashmap_entry *prev)
{
	void	*value;

	if (prev)
		prev->next = entry->next;
	else
		map->buckets[index] = entry->next;
	value = entry->value;
	key_free(entry->key);
	free(entry);
	map->size--;
	return (value);
}

void	*hashmap_remove(t_hashmap *map, const char *key)
{
	uint32_t		hash;
	size_t			index;
	t_hashmap_entry	*entry;
	t_hashmap_entry	*prev;

	if (!map || !key)
		return (NULL);
	hash = map->hash_func(key);
	index = hash % map->capacity;
	entry = map->buckets[index];
	prev = NULL;
	while (entry)
	{
		if (entry->hash == hash && map->key_cmp(entry->key, key) == 0)
			return (hashmap_remove_entry(map, index, entry, prev));
		prev = entry;
		entry = entry->next;
	}
	return (NULL);
}
