/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 02:58:16 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:54:04 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

void	*treemap_get(t_treemap *map, const char *key)
{
	t_treemap_node	*node;
	int				cmp;

	if (!map || !key)
		return (NULL);
	node = map->root;
	while (node != map->nil)
	{
		cmp = map->key_cmp(key, node->key);
		if (cmp == 0)
			return (node->value);
		if (cmp < 0)
			node = node->left;
		else
			node = node->right;
	}
	return (NULL);
}
