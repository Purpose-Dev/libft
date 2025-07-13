/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_push_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:40:09 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:24:37 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/lists/d/ft_dlist.h"

int	dlist_push_front(t_dlist *list, void *data)
{
	t_dlist_node	*node;

	if (!list)
		return (0);
	node = dlist_node_create(data);
	if (!node)
		return (0);
	if (list->head)
	{
		node->next = list->head;
		list->head->prev = node;
	}
	list->head = node;
	list->size++;
	return (1);
}
