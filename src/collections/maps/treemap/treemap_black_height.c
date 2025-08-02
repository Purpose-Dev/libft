/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_black_height.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:36:19 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 17:36:46 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

static size_t	black_height_helper(const t_treemap_node *node,
									t_treemap_node *nil)
{
	size_t	left_bh;
	size_t	right_bh;

	if (node == nil)
		return (1);
	left_bh = black_height_helper(node->left, nil);
	right_bh = black_height_helper(node->right, nil);
	if (left_bh != right_bh)
		return (0);
	if (node->color == RB_BLACK)
		return (left_bh + 1);
	else
		return (left_bh);
}

size_t	treemap_black_height(t_treemap *map)
{
	if (!map || map->root == map->nil)
		return (0);
	return (black_height_helper(map->root, map->nil));
}
