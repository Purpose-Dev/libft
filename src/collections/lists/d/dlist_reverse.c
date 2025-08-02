/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:41:17 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:19:58 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/lists/d/ft_dlist.h"

void	dlist_reverse(t_dlist *list)
{
	t_dlist_node	*current;
	t_dlist_node	*temp;

	if (!list || !list->head)
		return ;
	current = list->head;
	while (current)
	{
		temp = current->next;
		current->next = current->prev;
		current->prev = temp;
		if (!temp)
			list->head = current;
		current = temp;
	}
}
