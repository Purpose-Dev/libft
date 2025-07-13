/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_remove_at.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:30:07 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:36:52 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/lists/d/ft_dlist.h"

void	*dlist_remove_at(t_dlist *list, size_t index)
{
	t_dlist_node	*current;
	void			*data;
	size_t			i;

	if (!list || index >= list->size)
		return (NULL);
	current = list->head;
	i = 0;
	while (i < index && current)
	{
		current = current->next;
		i++;
	}
	if (!current)
		return (NULL);
	data = current->data;
	dlist_remove_node(list, current);
	return (data);
}
