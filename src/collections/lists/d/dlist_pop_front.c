/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_pop_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:29:44 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:33:10 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/lists/d/ft_dlist.h"

void	*dlist_pop_front(t_dlist *list)
{
	t_dlist_node	*node;
	void			*data;

	if (!list || !list->head)
		return (NULL);
	node = list->head;
	data = node->data;
	list->head = node->next;
	if (list->head)
		list->head->prev = NULL;
	free(node);
	list->size--;
	return (data);
}
