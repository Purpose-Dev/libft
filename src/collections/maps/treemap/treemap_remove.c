/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 02:58:36 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 17:09:57 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

void	*treemap_remove(t_treemap *map, const char *key)
{
	t_treemap_node	*current;
	int				cmp;

	if (!map || !key)
		return (NULL);
	current = map->root;
	while (current != map->nil)
	{
		cmp = map->key_cmp(key, current->key);
		if (cmp == 0)
		{
			map->size--;
			return (current->value);
		}
		if (cmp < 0)
			current = current->left;
		else
			current = current->right;
	}
	return (NULL);
}
