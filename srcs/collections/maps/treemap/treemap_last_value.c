/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_last_value.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 03:39:27 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/13 03:45:38 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

static t_treemap_node	*find_max_node(t_treemap_node *node,
							const t_treemap_node *nil)
{
	while (node->right != nil)
		node = node->right;
	return (node);
}

void	*treemap_last_value(t_treemap *map)
{
	t_treemap_node	*max_node;

	if (!map || map->root == map->nil)
		return (NULL);
	max_node = find_max_node(map->root, map->nil);
	return (max_node->value);
}
