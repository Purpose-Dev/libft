/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:25:02 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 17:27:33 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

void	treemap_foreach(t_treemap *map, void (*f)(const char *key, void *value))
{
	t_treemap_iterator	*it;
	t_treemap_node		*node;

	if (!map || !f)
		return ;
	it = treemap_iterator_create(map);
	if (!it)
		return ;
	while (treemap_iterator_has_next(it))
	{
		node = treemap_iterator_next(it);
		if (node)
			f(node->key, node->value);
	}
	treemap_iterator_destroy(it);
}
