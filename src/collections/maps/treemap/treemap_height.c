/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_height.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:35:58 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 17:37:12 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

static size_t	height_helper(const t_treemap_node *node,
								t_treemap_node *nil)
{
	size_t	left_height;
	size_t	right_height;

	if (node == nil)
		return (0);
	left_height = height_helper(node->left, nil);
	right_height = height_helper(node->right, nil);
	if (left_height > right_height)
		return (left_height + 1);
	else
		return (right_height + 1);
}

size_t	treemap_height(t_treemap *map)
{
	if (!map || map->root == map->nil)
		return (0);
	return (height_helper(map->root, map->nil));
}
