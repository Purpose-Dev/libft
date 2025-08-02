/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 08:09:29 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 21:41:08 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"

static char	**hashmap_keys_init(t_hashmap *map)
{
	char	**keys;

	if (!map || map->size == 0)
		return (NULL);
	keys = malloc(sizeof(char *) * (map->size + 1));
	if (!keys)
		return (NULL);
	return (keys);
}

static void	free_keys_array(char **keys, size_t count)
{
	while (count > 0)
		free(keys[--count]);
	free(keys);
}

static int	hashmap_keys_extract(const t_hashmap *map, char **keys)
{
	size_t			i;
	size_t			key_index;
	t_hashmap_entry	*entry;

	key_index = 0;
	i = 0;
	while (i < map->capacity)
	{
		entry = map->buckets[i];
		while (entry)
		{
			keys[key_index] = key_duplicate(entry->key);
			if (!keys[key_index])
			{
				free_keys_array(keys, key_index);
				return (-1);
			}
			key_index++;
			entry = entry->next;
		}
		i++;
	}
	keys[key_index] = NULL;
	return (0);
}

char	**hashmap_keys(t_hashmap *map)
{
	char	**keys;

	keys = hashmap_keys_init(map);
	if (!keys)
		return (NULL);
	if (hashmap_keys_extract(map, keys) == -1)
		return (NULL);
	return (keys);
}
