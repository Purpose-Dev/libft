/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_iterator_create.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:42:19 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 21:58:03 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"

static void	find_next_entry(t_hashmap_iterator *it)
{
	while (it->bucket_index < it->map->capacity)
	{
		if (it->map->buckets[it->bucket_index])
		{
			it->next = it->map->buckets[it->bucket_index];
			return ;
		}
		it->bucket_index++;
	}
	it->next = NULL;
}

t_hashmap_iterator	*hashmap_iterator_create(t_hashmap *map)
{
	t_hashmap_iterator	*it;

	if (!map)
		return (NULL);
	it = malloc(sizeof(t_hashmap_iterator));
	if (!it)
		return (NULL);
	it->map = map;
	it->current = NULL;
	it->bucket_index = 0;
	find_next_entry(it);
	return (it);
}
