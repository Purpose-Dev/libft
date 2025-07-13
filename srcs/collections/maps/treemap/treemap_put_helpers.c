/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_put_helpers.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:21:11 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:52:57 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

t_treemap_node	*create_node(const char *key, void *value, t_treemap_node *nil)
{
	t_treemap_node	*node;

	node = malloc(sizeof(t_treemap_node));
	if (!node)
		return (NULL);
	node->key = key_duplicate(key);
	if (!node->key)
	{
		free(node);
		return (NULL);
	}
	node->value = value;
	node->left = nil;
	node->right = nil;
	node->parent = nil;
	node->color = RB_RED;
	return (node);
}

static int	update_existing_node(t_treemap_node *x, void *value,
									t_treemap_node *z)
{
	x->value = value;
	key_free(z->key);
	free(z);
	return (1);
}

int	insert_new_node(t_treemap *map, t_treemap_node *z)
{
	t_treemap_node	*y;
	t_treemap_node	*x;
	int				cmp;

	y = map->nil;
	x = map->root;
	while (x != map->nil)
	{
		y = x;
		cmp = map->key_cmp(z->key, x->key);
		if (cmp == 0)
			return (update_existing_node(x, z->value, z));
		if (cmp < 0)
			x = x->left;
		else
			x = x->right;
	}
	z->parent = y;
	if (y == map->nil)
		map->root = z;
	else if (map->key_cmp(z->key, y->key) < 0)
		y->left = z;
	else
		y->right = z;
	return (0);
}
