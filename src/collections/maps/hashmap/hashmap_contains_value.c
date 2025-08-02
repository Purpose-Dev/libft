/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_contains_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 05:52:52 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 06:27:15 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"

int	hashmap_contains_value(t_hashmap *map, void *value,
							int (*cmp)(void *, void *))
{
	size_t			i;
	t_hashmap_entry	*entry;

	if (!map || !cmp)
		return (0);
	i = 0;
	while (i < map->capacity)
	{
		entry = map->buckets[i];
		while (entry)
		{
			if (cmp(entry->value, value) == 0)
				return (1);
			entry = entry->next;
		}
		i++;
	}
	return (0);
}
