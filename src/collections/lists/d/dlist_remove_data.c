/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_remove_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:30:21 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:38:20 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/lists/d/ft_dlist.h"

int	dlist_remove_data(t_dlist *list, void *data, int (*cmp)(void *, void *))
{
	t_dlist_node	*current;

	if (!list || !cmp)
		return (0);
	current = list->head;
	while (current)
	{
		if (cmp(current->data, data) == 0)
		{
			dlist_remove_node(list, current);
			return (1);
		}
		current = current->next;
	}
	return (0);
}
