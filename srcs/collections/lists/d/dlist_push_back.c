/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_push_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:40:29 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:23:39 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/lists/d/ft_dlist.h"

int	dlist_push_back(t_dlist *list, void *data)
{
	t_dlist_node	*node;
	t_dlist_node	*last;

	if (!list)
		return (0);
	node = dlist_node_create(data);
	if (!node)
		return (0);
	if (!list->head)
	{
		list->head = node;
		list->size++;
		return (1);
	}
	last = list->head;
	while (last->next)
		last = last->next;
	last->next = node;
	node->prev = last;
	list->size++;
	return (1);
}
