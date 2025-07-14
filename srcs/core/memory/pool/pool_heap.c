/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool_heap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:08:50 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/14 15:35:53 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/memory/pool/memory_pool.h"

t_heap_pool	*heap_pool_create(size_t size)
{
	t_heap_pool	*pool;

	if (size == 0)
		size = HEAP_POOL_DEFAULT_SIZE;
	pool = malloc(sizeof(t_heap_pool));
	if (!pool)
		return (NULL);
	pool->memory = malloc(size);
	if (!pool->memory)
	{
		free(pool);
		return (NULL);
	}
	pool->total_size = size;
	pool->used_size = 0;
	pool->offset = 0;
	pool->blocks = NULL;
	return (pool);
}

void	heap_pool_destroy(t_heap_pool *pool)
{
	t_memory_block	*current;
	t_memory_block	*next;

	if (!pool)
		return ;
	current = pool->blocks;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	if (pool->memory)
		free(pool->memory);
	free(pool);
}

void	heap_pool_reset(t_heap_pool *pool)
{
	t_memory_block	*current;
	t_memory_block	*next;

	if (!pool)
		return ;
	current = pool->blocks;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	pool->blocks = NULL;
	pool->offset = 0;
	pool->used_size = 0;
}

size_t	heap_pool_available(t_heap_pool *pool)
{
	if (!pool)
		return (0);
	return (pool->total_size - pool->used_size);
}

size_t	heap_pool_used(t_heap_pool *pool)
{
	if (!pool)
		return (0);
	return (pool->used_size);
}
