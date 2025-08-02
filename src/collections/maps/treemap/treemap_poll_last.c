/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_poll_last.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:49:23 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/03 00:56:02 by rel-qoqu         ###   ########.fr       */
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

void	*treemap_poll_last(t_treemap *map)
{
	t_treemap_node	*max_node;
	char			*key;
	void			*value;

	if (!map || map->root == map->nil)
		return (NULL);
	max_node = find_max_node(map->root, map->nil);
	value = max_node->value;
	key = key_duplicate(max_node->key);
	if (!key)
		return (NULL);
	treemap_remove(map, key);
	key_free(key);
	return (value);
}
