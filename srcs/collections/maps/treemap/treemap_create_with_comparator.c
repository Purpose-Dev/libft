/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_create_with_comparator.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 08:21:13 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/11 03:33:13 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps//treemap/ft_treemap.h"

static t_treemap_node	*create_nil_node(void)
{
	t_treemap_node	*nil;

	nil = malloc(sizeof(t_treemap_node));
	if (!nil)
		return (NULL);
	nil->key = NULL;
	nil->value = NULL;
	nil->left = nil;
	nil->right = nil;
	nil->parent = nil;
	nil->color = RB_BLACK;
	return (nil);
}

t_treemap	*treemap_create_with_comparator(
				int (*cmp)(const char *, const char *))
{
	t_treemap	*treemap;

	if (!cmp)
		return (NULL);
	treemap = malloc(sizeof(t_treemap));
	if (!treemap)
		return (NULL);
	treemap->nil = create_nil_node();
	if (!treemap->nil)
	{
		free(treemap);
		return (NULL);
	}
	treemap->root = treemap->nil;
	treemap->key_cmp = cmp;
	treemap->size = 0;
	return (treemap);
}
