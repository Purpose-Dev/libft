/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_insert_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:40:47 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:26:38 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/lists/d/ft_dlist.h"

int	dlist_insert_at(t_dlist *list, const size_t index, void *data)
{
	t_dlist_node	*current;
	size_t			i;

	if (!list || index > list->size)
		return (0);
	if (index == 0)
		return (dlist_push_front(list, data));
	current = list->head;
	i = 0;
	while (i < index && current)
	{
		current = current->next;
		i++;
	}
	if (!current)
		return (dlist_push_back(list, data));
	return (dlist_insert_before(list, current, data));
}
