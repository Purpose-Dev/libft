/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_destroy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 08:21:31 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:53:57 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

static void	destroy_node(t_treemap_node *node, t_treemap_node *nil,
						void (*value_del)(void *))
{
	if (node == nil)
		return ;
	destroy_node(node->left, nil, value_del);
	destroy_node(node->right, nil, value_del);
	if (value_del && node->value)
		value_del(node->value);
	key_free(node->key);
	free(node);
}

void	treemap_destroy(t_treemap *map, void (*value_del)(void *))
{
	if (!map)
		return ;
	destroy_node(map->root, map->nil, value_del);
	free(map->nil);
	free(map);
}
