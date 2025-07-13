/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_submap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:15:20 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 17:22:29 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

t_treemap	*treemap_submap(t_treemap *map, const char *from_key,
						const char *to_key)
{
	t_treemap	*new_map;

	if (!map || !from_key || !to_key)
		return (NULL);
	new_map = treemap_create_with_comparator(map->key_cmp);
	return (new_map);
}
