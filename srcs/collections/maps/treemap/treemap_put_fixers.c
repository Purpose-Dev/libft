/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_put_fixers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 10:21:05 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:52:45 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

static void	fixup_left_case(t_treemap *map, t_treemap_node **z)
{
	t_treemap_node	*y;

	y = (*z)->parent->parent->right;
	if (y->color == RB_RED)
	{
		(*z)->parent->color = RB_BLACK;
		y->color = RB_BLACK;
		(*z)->parent->parent->color = RB_RED;
		*z = (*z)->parent->parent;
	}
	else
	{
		if (*z == (*z)->parent->right)
		{
			*z = (*z)->parent;
			rotate_left(map, *z);
		}
		(*z)->parent->color = RB_BLACK;
		(*z)->parent->parent->color = RB_RED;
		rotate_right(map, (*z)->parent->parent);
	}
}

static void	fixup_right_case(t_treemap *map, t_treemap_node **z)
{
	t_treemap_node	*y;

	y = (*z)->parent->parent->left;
	if (y->color == RB_RED)
	{
		(*z)->parent->color = RB_BLACK;
		y->color = RB_BLACK;
		(*z)->parent->parent->color = RB_RED;
		*z = (*z)->parent->parent;
	}
	else
	{
		if (*z == (*z)->parent->left)
		{
			*z = (*z)->parent;
			rotate_right(map, *z);
		}
		(*z)->parent->color = RB_BLACK;
		(*z)->parent->parent->color = RB_RED;
		rotate_left(map, (*z)->parent->parent);
	}
}

void	insert_fixup(t_treemap *map, t_treemap_node *z)
{
	while (z->parent->color == RB_RED)
	{
		if (z->parent == z->parent->parent->left)
			fixup_left_case(map, &z);
		else
			fixup_right_case(map, &z);
	}
	map->root->color = RB_BLACK;
}
