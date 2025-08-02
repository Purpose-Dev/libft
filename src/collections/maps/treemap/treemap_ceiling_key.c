/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_ceiling_key.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:48:32 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/03 09:37:44 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

char	*treemap_ceiling_key(t_treemap *map, const char *key)
{
	t_treemap_node	*node;
	t_treemap_node	*result;
	int				cmp;

	if (!map || !key)
		return (NULL);
	node = map->root;
	result = NULL;
	while (node != map->nil)
	{
		cmp = map->key_cmp(key, node->key);
		if (cmp == 0)
			return (node->key);
		if (cmp < 0)
		{
			result = node;
			node = node->left;
		}
		else
			node = node->right;
	}
	if (result)
		return (result->key);
	return (NULL);
}
