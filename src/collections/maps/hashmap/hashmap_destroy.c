/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 03:07:54 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 05:45:49 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"

static void	destroy_entry_ch(t_hashmap_entry *entry, void (*value_del)(void *))
{
	t_hashmap_entry	*next;

	while (entry)
	{
		next = entry->next;
		if (value_del && entry->value)
			value_del(entry->value);
		key_free(entry->key);
		free(entry);
		entry = next;
	}
}

void	hashmap_destroy(t_hashmap *map, void (*value_del)(void *))
{
	size_t	i;

	if (!map)
		return ;
	if (map->buckets)
	{
		i = 0;
		while (i < map->capacity)
		{
			if (map->buckets[i])
				destroy_entry_ch(map->buckets[i], value_del);
			i++;
		}
		free(map->buckets);
	}
	free(map);
}
