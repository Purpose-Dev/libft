/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 15:39:35 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 15:56:11 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/lists/d/ft_dlist.h"

void	dlist_destroy(t_dlist *list, void (*del)(void *))
{
	if (!list)
		return ;
	dlist_clear(list, del);
	free(list);
}
