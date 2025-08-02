/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_forearch.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:40:29 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:49:44 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/lists/d/ft_dlist.h"

void	dlist_foreach(t_dlist *list, void (*f)(void *))
{
	t_dlist_node	*current;

	if (!list || !f)
		return ;
	current = list->head;
	while (current)
	{
		f(current->data);
		current = current->next;
	}
}
