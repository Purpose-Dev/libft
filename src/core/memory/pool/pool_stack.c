/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:08:29 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/14 14:20:42 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/memory/pool/memory_pool.h"

bool	stack_pool_init(t_stack_pool *pool, void *buffer, const size_t size)
{
	if (!pool || !buffer || size == 0)
		return (false);
	pool->memory = buffer;
	pool->total_size = size;
	pool->offset = 0;
	return (true);
}

void	*stack_pool_alloc(t_stack_pool *pool, const size_t size)
{
	size_t	aligned_size;
	void	*ptr;

	if (!pool || size == 0)
		return (NULL);
	aligned_size = (size + MEMORY_POOL_ALIGN - 1)
		& ~((size_t)MEMORY_POOL_ALIGN - 1);
	if (pool->offset + aligned_size > pool->total_size)
		return (NULL);
	ptr = (char *)pool->memory + pool->offset;
	pool->offset += aligned_size;
	return (ptr);
}

void	stack_pool_reset(t_stack_pool *pool)
{
	if (!pool)
		return ;
	pool->offset = 0;
}

size_t	stack_pool_available(t_stack_pool *pool)
{
	if (!pool)
		return (0);
	return (pool->total_size - pool->offset);
}

size_t	stack_pool_used(t_stack_pool *pool)
{
	if (!pool)
		return (0);
	return (pool->offset);
}
