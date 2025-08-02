/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 08:09:37 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 21:41:01 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"

static void	**hashmap_values_init(t_hashmap *map)
{
	void	**values;

	if (!map || map->size == 0)
		return (NULL);
	values = malloc(sizeof(void *) * (map->size + 1));
	return (values);
}

static void	extract_bucket_values(const t_hashmap_entry *entry, void **values,
									size_t *value_index)
{
	while (entry)
	{
		values[*value_index] = entry->value;
		(*value_index)++;
		entry = entry->next;
	}
}

static int	hashmap_values_extract(const t_hashmap *map, void **values)
{
	size_t	i;
	size_t	value_index;

	value_index = 0;
	i = 0;
	while (i < map->capacity)
	{
		if (map->buckets[i])
			extract_bucket_values(map->buckets[i], values, &value_index);
		i++;
	}
	values[value_index] = NULL;
	return (0);
}

void	**hashmap_values(t_hashmap *map)
{
	void			**values;

	values = hashmap_values_init(map);
	if (!values)
		return (NULL);
	hashmap_values_extract(map, values);
	return (values);
}
