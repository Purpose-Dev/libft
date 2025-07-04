/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_first_value.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 03:39:42 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/13 03:45:25 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

static t_treemap_node	*find_min_node(t_treemap_node *node,
										const t_treemap_node *nil)
{
	while (node->left != nil)
		node = node->left;
	return (node);
}

void	*treemap_first_value(t_treemap *map)
{
	t_treemap_node	*min_node;

	if (!map || map->root == map->nil)
		return (NULL);
	min_node = find_min_node(map->root, map->nil);
	return (min_node->value);
}
