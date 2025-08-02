/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:43:24 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 21:57:48 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"

void	hashmap_foreach(t_hashmap *map,
	void (*f)(const char *key, void *value))
{
	size_t			i;
	t_hashmap_entry	*entry;

	if (!map || !f)
		return ;
	i = 0;
	while (i < map->capacity)
	{
		entry = map->buckets[i];
		while (entry)
		{
			f(entry->key, entry->value);
			entry = entry->next;
		}
		i++;
	}
}
