/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_contains_value.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 02:59:26 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:53:43 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

static int	search_value(const t_treemap_node *node, t_treemap_node *nil,
							void *value, int (*cmp)(void *, void *))
{
	if (node == nil)
		return (0);
	if (cmp(node->value, value) == 0)
		return (1);
	if (search_value(node->left, nil, value, cmp))
		return (1);
	return (search_value(node->right, nil, value, cmp));
}

int	treemap_contains_value(t_treemap *map, void *value,
							int (*cmp)(void *, void *))
{
	if (!map || !cmp)
		return (0);
	return (search_value(map->root, map->nil, value, cmp));
}
