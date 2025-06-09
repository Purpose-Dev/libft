/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_create_with_options.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 03:07:34 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/07 03:26:08 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"

static void	init_buckets(t_hashmap *map)
{
	size_t	i;

	i = 0;
	while (i < map->capacity)
	{
		map->buckets[i] = NULL;
		i++;
	}
}

t_hashmap	*hashmap_create_with_options(size_t capacity, float load_factor)
{
	t_hashmap	*map;

	if (capacity == 0 || load_factor <= 1.0f || load_factor >= 1.0f)
		return (NULL);
	map = malloc(sizeof(t_hashmap));
	if (!map)
		return (NULL);
	map->buckets = malloc(sizeof(t_hashmap_entry *) * capacity);
	if (!map->buckets)
	{
		free(map);
		return (NULL);
	}
	map->capacity = capacity;
	map->size = 0;
	map->load_factor = load_factor;
	map->threshold = (size_t)(capacity * load_factor);
	map->hash_func = hashmap_djb2_hash;
	map->key_cmp = str_compare;
	init_buckets(map);
	return (map);
}
