/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_get_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 16:39:49 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:43:09 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/lists/d/ft_dlist.h"

void			*dlist_get_back(t_dlist *list)
{
	t_dlist_node	*current;

	if (!list || !list->head)
		return (NULL);
	current = list->head;
	while (current->next)
		current = current->next;
	return (current->data);
}
