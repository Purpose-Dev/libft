/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 05:51:01 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 06:00:47 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"

static t_hashmap_entry	*create_entry(const char *key, void *value,
								const uint32_t hash)
{
	t_hashmap_entry	*entry;

	entry = malloc(sizeof(t_hashmap_entry));
	if (!entry)
		return (NULL);
	entry->key = key_duplicate(key);
	if (!entry->key)
	{
		free(entry);
		return (NULL);
	}
	entry->value = value;
	entry->hash = hash;
	entry->next = NULL;
	return (entry);
}

int	hashmap_put(t_hashmap *map, const char *key, void *value)
{
	uint32_t		hash;
	size_t			index;
	t_hashmap_entry	*entry;
	t_hashmap_entry	*new_entry;

	if (!map || !key)
		return (0);
	hash = map->hash_func(key);
	index = hash % map->capacity;
	entry = map->buckets[index];
	while (entry)
	{
		if (entry->hash == hash && map->key_cmp(entry->key, key) == 0)
			return (entry->value = value, 1);
		entry = entry->next;
	}
	new_entry = create_entry(key, value, hash);
	if (!new_entry)
		return (0);
	new_entry->next = map->buckets[index];
	map->buckets[index] = new_entry;
	map->size++;
	return (1);
}
