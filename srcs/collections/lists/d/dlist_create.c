/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:39:13 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 15:55:31 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/lists/d/ft_dlist.h"

t_dlist	*dlist_create(void)
{
	t_dlist	*list;

	list = malloc(sizeof(t_dlist));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->size = 0;
	return (list);
}
