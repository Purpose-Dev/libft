/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 02:57:44 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:54:11 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

int	treemap_put(t_treemap *map, const char *key, void *value)
{
	t_treemap_node	*z;
	int				is_update;

	if (!map || !key)
		return (0);
	z = create_node(key, value, map->nil);
	if (!z)
		return (0);
	is_update = insert_new_node(map, z);
	if (is_update)
		return (1);
	insert_fixup(map, z);
	map->size++;
	return (1);
}
