/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:08:56 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/14 15:35:40 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/memory/pool/memory_pool.h"

static size_t	align_size(const size_t size)
{
	return ((size + MEMORY_POOL_ALIGN - 1) & ~((size_t)MEMORY_POOL_ALIGN - 1));
}

static t_memory_block	*create_block(void *ptr, const size_t size)
{
	t_memory_block	*block;

	block = malloc(sizeof(t_memory_block));
	if (!block)
		return (NULL);
	block->ptr = ptr;
	block->size = size;
	block->is_free = false;
	block->next = NULL;
	return (block);
}

static void	add_block(t_heap_pool *pool, t_memory_block *block)
{
	block->next = pool->blocks;
	pool->blocks = block;
}

void	*heap_pool_alloc(t_heap_pool *pool, const size_t size)
{
	size_t			aligned_size;
	void			*ptr;
	t_memory_block	*block;

	if (!pool || size == 0)
		return (NULL);
	aligned_size = align_size(size);
	if (pool->offset + aligned_size > pool->total_size)
		return (NULL);
	ptr = (char *)pool->memory + pool->offset;
	block = create_block(ptr, aligned_size);
	if (!block)
		return (NULL);
	add_block(pool, block);
	pool->offset += aligned_size;
	pool->used_size += aligned_size;
	return (ptr);
}
