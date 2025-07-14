/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pool_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 14:09:06 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/14 15:40:48 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/memory/pool/memory_pool.h"
#include "io/ft_printf.h"

bool	heap_pool_contains(t_heap_pool *pool, void *ptr)
{
	char	*start;
	char	*end;

	if (!pool || !ptr)
		return (false);
	start = (char *)pool->memory;
	end = start + pool->total_size;
	return (ptr >= (void *)start && ptr < (void *)end);
}

void	heap_pool_stats(t_heap_pool *pool)
{
	t_memory_block	*current;
	int				block_count;
	int				free_count;

	if (!pool)
		return ;
	block_count = 0;
	free_count = 0;
	current = pool->blocks;
	while (current)
	{
		block_count++;
		if (current->is_free)
			free_count++;
		current = current->next;
	}
	ft_printf("Heap Pool Stats:\n");
	ft_printf("  Total size: %zu bytes\n", pool->total_size);
	ft_printf("  Used size: %zu bytes\n", pool->used_size);
	ft_printf("  Available: %zu bytes\n", pool->total_size - pool->used_size);
	ft_printf("  Blocks: %d (%d free)\n", block_count, free_count);
}
