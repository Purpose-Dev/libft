/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_preorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:30:11 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 17:34:15 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

static void	preorder_helper(const t_treemap_node *node, t_treemap_node *nil,
						void (*f)(const char *key, void *value))
{
	if (node == nil)
		return ;
	f(node->key, node->value);
	preorder_helper(node->left, nil, f);
	preorder_helper(node->right, nil, f);
}

void	treemap_preorder(t_treemap *map,
							void (*f)(const char *key, void *value))
{
	if (!map || !f)
		return ;
	preorder_helper(map->root, map->nil, f);
}
