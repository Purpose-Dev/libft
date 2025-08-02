/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:40:03 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:45:05 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/lists/d/ft_dlist.h"

t_dlist_node	*dlist_find(t_dlist *list, void *data,
					int (*cmp)(void *, void *))
{
	t_dlist_node	*current;

	if (!list || !cmp)
		return (NULL);
	current = list->head;
	while (current)
	{
		if (cmp(current->data, data) == 0)
			return (current);
		current = current->next;
	}
	return (NULL);
}
