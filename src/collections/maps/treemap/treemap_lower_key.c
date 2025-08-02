/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_lower_key.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 04:26:13 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/13 04:31:59 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

char	*treemap_lower_key(t_treemap *map, const char *key)
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
		if (cmp <= 0)
			node = node->left;
		else
		{
			result = node;
			node = node->right;
		}
	}
	if (result)
		return (result->key);
	return (NULL);
}
