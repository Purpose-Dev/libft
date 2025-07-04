/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:49:43 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/03 09:52:11 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

static void	collect_keys(const t_treemap_node *node, t_treemap_node *nil,
							char **keys, size_t *index)
{
	if (node == nil)
		return ;
	collect_keys(node->left, nil, keys, index);
	keys[*index] = key_duplicate(node->key);
	(*index)++;
	collect_keys(node->right, nil, keys, index);
}

char	**treemap_keys(t_treemap *map)
{
	char	**keys;
	size_t	index;

	if (!map || map->size == 0)
		return (NULL);
	keys = malloc(sizeof(char *) * (map->size + 1));
	if (!keys)
		return (NULL);
	index = 0;
	collect_keys(map->root, map->nil, keys, &index);
	keys[map->size] = NULL;
	return (keys);
}
