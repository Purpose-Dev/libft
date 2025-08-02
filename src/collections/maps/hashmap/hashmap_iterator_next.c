/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashmap_iterator_next.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 21:42:49 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/09 21:57:53 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/maps/hashmap/ft_hashmap.h"

static void	advance_iterator(t_hashmap_iterator *it)
{
	if (it->current->next)
	{
		it->next = it->current->next;
		return ;
	}
	it->bucket_index++;
	while (it->bucket_index < it->map->capacity)
	{
		if (it->map->buckets[it->bucket_index])
		{
			it->next = it->map->buckets[it->bucket_index];
			return ;
		}
		it->bucket_index++;
	}
	it->next = NULL;
}

t_hashmap_entry	*hashmap_iterator_next(t_hashmap_iterator *it)
{
	if (!it || !it->next)
		return (NULL);
	it->current = it->next;
	advance_iterator(it);
	return (it->current);
}
