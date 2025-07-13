/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_insert_after.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:40:54 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:27:53 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/lists/d/ft_dlist.h"

int	dlist_insert_after(t_dlist *list, t_dlist_node *node, void *data)
{
	t_dlist_node	*new_node;

	if (!list || !node)
		return (0);
	new_node = dlist_node_create(data);
	if (!new_node)
		return (0);
	new_node->next = node->next;
	new_node->prev = node;
	if (node->next)
		node->next->prev = new_node;
	node->next = new_node;
	list->size++;
	return (1);
}
