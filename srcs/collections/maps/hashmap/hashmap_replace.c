/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_replace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 06:20:33 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 06:27:43 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"

void	*hashmap_replace(t_hashmap *map, const char *key, void *new_value)
{
	uint32_t		hash;
	size_t			index;
	t_hashmap_entry	*entry;
	void			*old_value;

	if (!map || !key)
		return (NULL);
	hash = map->hash_func(key);
	index = hash % map->capacity;
	entry = map->buckets[index];
	while (entry)
	{
		if (entry->hash == hash && map->key_cmp(entry->key, key) == 0)
		{
			old_value = entry->value;
			entry->value = new_value;
			return (old_value);
		}
		entry = entry->next;
	}
	return (NULL);
}
