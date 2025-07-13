/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:39:51 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:15:59 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/lists/d/ft_dlist.h"

size_t	dlist_size(t_dlist *list)
{
	if (!list)
		return (0);
	return (list->size);
}
