/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_is_valid_rb_tree.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:35:34 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 17:39:09 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

static int	validate_rb_properties(const t_treemap_node *node,
								t_treemap_node *nil, int black_count,
								int *path_black_count)
{
	if (node == nil)
	{
		if (*path_black_count == -1)
			*path_black_count = black_count;
		return (*path_black_count == black_count);
	}
	if (node->color == RB_RED)
	{
		if ((node->left != nil && node->left->color == RB_RED)
			|| (node->right != nil && node->right->color == RB_RED))
			return (0);
	}
	if (node->color == RB_BLACK)
		black_count++;
	return (validate_rb_properties(node->left, nil,
			black_count, path_black_count)
		&& validate_rb_properties(node->right, nil,
			black_count, path_black_count));
}

int	treemap_is_valid_rb_tree(t_treemap *map)
{
	int	path_black_count;

	if (!map)
		return (0);
	if (map->root == map->nil)
		return (1);
	if (map->root->color != RB_BLACK)
		return (0);
	path_black_count = -1;
	return (validate_rb_properties(map->root, map->nil, 0, &path_black_count));
}
