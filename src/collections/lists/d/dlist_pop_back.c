/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_pop_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:29:57 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:34:31 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/lists/d/ft_dlist.h"

void	*dlist_pop_back(t_dlist *list)
{
	t_dlist_node	*node;
	void			*data;

	if (!list || !list->head)
		return (NULL);
	node = list->head;
	while (node->next)
		node = node->next;
	data = node->data;
	if (node->prev)
		node->prev->next = NULL;
	else
		list->head = NULL;
	free(node);
	list->size--;
	return (data);
}
