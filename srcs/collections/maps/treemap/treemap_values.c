/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 00:50:02 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/04 09:49:16 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

static void	collect_values(const t_treemap_node *node, t_treemap_node *nil,
							void **values, size_t *index)
{
	if (node == nil)
		return ;
	collect_values(node->left, nil, values, index);
	values[*index] = node->value;
	(*index)++;
	collect_values(node->left, nil, values, index);
}

void	**treemap_values(t_treemap *map)
{
	void	**values;
	size_t	index;

	if (!map || map->size == 0)
		return (NULL);
	values = malloc(sizeof(void *) * (map->size + 1));
	if (!values)
		return (NULL);
	index = 0;
	collect_values(map->root, map->nil, values, &index);
	values[map->size] = NULL;
	return (values);
}
