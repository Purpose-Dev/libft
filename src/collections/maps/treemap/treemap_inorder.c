/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_inorder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:29:54 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 17:33:40 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

static void	inorder_helper(const t_treemap_node *node, t_treemap_node *nil,
							void (*f)(const char *key, void *value))
{
	if (node == nil)
		return ;
	inorder_helper(node->left, nil, f);
	f(node->key, node->value);
	inorder_helper(node->right, nil, f);
}

void	treemap_inorder(t_treemap *map,
						void (*f)(const char *key, void *value))
{
	if (!map || !f)
		return ;
	inorder_helper(map->root, map->nil, f);
}
