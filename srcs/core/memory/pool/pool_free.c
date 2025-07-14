/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:09:01 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/14 15:35:27 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/memory/ft_memory.h"
#include "core/memory/pool/memory_pool.h"

static t_memory_block	*find_block(const t_heap_pool *pool, const void *ptr)
{
	t_memory_block	*current;

	current = pool->blocks;
	while (current)
	{
		if (current->ptr == ptr)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	heap_pool_free(t_heap_pool *pool, void *ptr)
{
	t_memory_block	*block;

	if (!pool || !ptr)
		return ;
	block = find_block(pool, ptr);
	if (!block)
		return ;
	block->is_free = true;
}

void	*heap_pool_realloc(t_heap_pool *pool, void *ptr, const size_t new_size)
{
	t_memory_block	*block;
	void			*new_ptr;

	if (!pool)
		return (NULL);
	if (!ptr)
		return (heap_pool_alloc(pool, new_size));
	if (new_size == 0)
	{
		heap_pool_free(pool, ptr);
		return (NULL);
	}
	block = find_block(pool, ptr);
	if (!block)
		return (NULL);
	if (block->size >= new_size)
		return (ptr);
	new_ptr = heap_pool_alloc(pool, new_size);
	if (!new_ptr)
		return (NULL);
	ft_memcpy(new_ptr, ptr, block->size);
	heap_pool_free(pool, ptr);
	return (new_ptr);
}
