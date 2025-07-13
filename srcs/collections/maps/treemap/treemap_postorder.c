/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_postorder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:30:20 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 17:34:52 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

static void	postorder_helper(const t_treemap_node *node, t_treemap_node *nil,
						void (*f)(const char *key, void *value))
{
	if (node == nil)
		return ;
	postorder_helper(node->left, nil, f);
	postorder_helper(node->right, nil, f);
	f(node->key, node->value);
}

void	treemap_postorder(t_treemap *map,
							void (*f)(const char *key, void *value))
{
	if (!map || !f)
		return ;
	postorder_helper(map->root, map->nil, f);
}
