/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 03:08:23 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 05:46:51 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"

static void	clear_entry_chain(t_hashmap_entry *entry, void (*value_del)(void *))
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

void	hashmap_clear(t_hashmap *map, void (*value_del)(void *))
{
	size_t	i;

	if (!map || !map->buckets)
		return ;
	i = 0;
	while (i < map->capacity)
	{
		if (map->buckets[i])
		{
			clear_entry_chain(map->buckets[i], value_del);
			map->buckets[i] = NULL;
		}
		i++;
	}
	map->size = 0;
}
