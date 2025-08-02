/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_iterator_create.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:22:00 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 17:25:47 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

t_treemap_iterator	*treemap_iterator_create(t_treemap *map)
{
	t_treemap_iterator	*it;

	if (!map)
		return (NULL);
	it = malloc(sizeof(t_treemap_iterator));
	if (!it)
		return (NULL);
	it->map = map;
	it->current = NULL;
	it->reverse = 0;
	it->stack_capacity = 32;
	it->stack_size = 0;
	it->stack = malloc(sizeof(t_treemap_node *) * it->stack_capacity);
	if (!it->stack)
	{
		free(it);
		return (NULL);
	}
	return (it);
}
