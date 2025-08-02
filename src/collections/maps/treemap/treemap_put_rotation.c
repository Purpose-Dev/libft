/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_put_rotation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:20:07 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/04 10:29:24 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

void	rotate_left(t_treemap *map, t_treemap_node *x)
{
	t_treemap_node	*y;

	y = x->right;
	x->right = y->left;
	if (y->left != map->nil)
		y->left->parent = x;
	y->parent = x->parent;
	if (x->parent == map->nil)
		map->root = y;
	else if (x == x->parent->left)
		x->parent->left = y;
	else
		x->parent->right = y;
	y->left = x;
	x->parent = y;
}

void	rotate_right(t_treemap *map, t_treemap_node *x)
{
	t_treemap_node	*y;

	y = x->left;
	x->left = y->right;
	if (y->right != map->nil)
		y->right->parent = x;
	y->parent = x->parent;
	if (x->parent == map->nil)
		map->root = y;
	else if (x == x->parent->right)
		x->parent->right = y;
	else
		x->parent->left = y;
	y->right = x;
	x->parent = y;
}
