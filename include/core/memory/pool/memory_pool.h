/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory_pool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 12:56:34 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/14 14:27:54 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_POOL_H
# define MEMORY_POOL_H

# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>

# define MEMORY_POOL_ALIGN 8
# define STACK_POOL_SIZE 4096
# define HEAP_POOL_DEFAULT_SIZE 8192

// Stack pool
typedef struct s_stack_pool
{
	void	*memory;
	size_t	total_size;
	size_t	offset;
	bool	is_heap_allocated;
	char	padding[7];
}	t_stack_pool;

// Heap pool
typedef struct s_memory_block
{
	struct s_memory_block	*next;
	void					*ptr;
	size_t					size;
	bool					is_free;
	char					padding[7];
}	t_memory_block;

typedef struct s_heap_pool
{
	t_memory_block	*blocks;
	void			*memory;
	size_t			total_size;
	size_t			used_size;
	size_t			offset;
	bool			is_heap_allocated;
	char			padding[7];
}	t_heap_pool;

// Stack pool operations
bool		stack_pool_init(t_stack_pool *pool, void *buffer, size_t size);
void		*stack_pool_alloc(t_stack_pool *pool, size_t size);
void		stack_pool_reset(t_stack_pool *pool);
size_t		stack_pool_available(t_stack_pool *pool);
size_t		stack_pool_used(t_stack_pool *pool);

// Heap pool operations
t_heap_pool	*heap_pool_create(size_t size);
void		heap_pool_destroy(t_heap_pool *pool);
void		*heap_pool_alloc(t_heap_pool *pool, size_t size);
void		heap_pool_free(t_heap_pool *pool, void *ptr);
void		heap_pool_reset(t_heap_pool *pool);
void		*heap_pool_realloc(t_heap_pool *pool, void *ptr, size_t new_size);
bool		heap_pool_contains(t_heap_pool *pool, void *ptr);
void		heap_pool_stats(t_heap_pool *pool);
size_t		heap_pool_available(t_heap_pool *pool);
size_t		heap_pool_used(t_heap_pool *pool);

#endif // MEMORY_POOL_H
