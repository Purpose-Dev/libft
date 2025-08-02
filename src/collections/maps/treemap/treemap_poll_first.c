/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_poll_first.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:48:56 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/03 00:58:46 by rel-qoqu         ###   ########.fr       */
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

void	*treemap_poll_first(t_treemap *map)
{
	t_treemap_node	*min_node;
	char			*key;
	void			*value;

	if (!map || map->root == map->nil)
		return (NULL);
	min_node = find_min_node(map->root, map->nil);
	key = key_duplicate(min_node->key);
	value = min_node->value;
	if (!key)
		return (NULL);
	treemap_remove(map, key);
	key_free(key);
	return (value);
}
