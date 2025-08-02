/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_insert_before.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:40:58 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:28:39 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/lists/d/ft_dlist.h"

int	dlist_insert_before(t_dlist *list, t_dlist_node *node, void *data)
{
	t_dlist_node	*new_node;

	if (!list || !node)
		return (0);
	new_node = dlist_node_create(data);
	if (!new_node)
		return (0);
	new_node->next = node;
	new_node->prev = node->prev;
	if (node->prev)
		node->prev->next = new_node;
	else
		list->head = new_node;
	node->prev = new_node;
	list->size++;
	return (1);
}
