/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_clear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:44:33 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:18:37 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/lists/d/ft_dlist.h"

void	dlist_clear(t_dlist *list, void (*del)(void *))
{
	t_dlist_node	*current;
	t_dlist_node	*next;

	if (!list)
		return ;
	current = list->head;
	while (current)
	{
		next = current->next;
		if (del)
			del(current->data);
		free(current);
		current = next;
	}
	list->head = NULL;
	list->size = 0;
}
