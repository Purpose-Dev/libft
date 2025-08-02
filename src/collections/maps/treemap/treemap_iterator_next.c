/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treemap_iterator_next.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:24:44 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 17:26:50 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/treemap/ft_treemap.h"

t_treemap_node	*treemap_iterator_next(t_treemap_iterator *it)
{
	if (!it || it->stack_size == 0)
		return (NULL);
	it->current = it->stack[--it->stack_size];
	return (it->current);
}
