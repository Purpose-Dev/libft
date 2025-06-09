/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_replace_if_equals.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 08:02:32 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 08:07:03 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"

int	hashmap_replace_if_equals(t_hashmap *map, const char *key, void *old_value,
								void *new_value)
{
	uint32_t		hash;
	size_t			index;
	t_hashmap_entry	*entry;

	if (!map || !key)
		return (0);
	hash = map->hash_func(key);
	index = hash % map->capacity;
	entry = map->buckets[index];
	while (entry)
	{
		if (entry->hash == hash && map->key_cmp(entry->key, key) == 0)
		{
			if (entry->value == old_value)
			{
				entry->value = new_value;
				return (1);
			}
			return (0);
		}
		entry = entry->next;
	}
	return (0);
}
