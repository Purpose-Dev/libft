/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_pool_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:50:56 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/14 22:35:55 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/threading/thread_pool.h"

static int	validate_thread_count(const int thread_count)
{
	if (thread_count <= 0 || thread_count > THREAD_POOL_MAX_SIZE)
		return (THREAD_POOL_DEFAULT_SIZE);
	return (thread_count);
}

static bool	init_pool_memory(t_thread_pool *pool, const int thread_count)
{
	pool->threads = malloc(sizeof(pthread_t) * (size_t)thread_count);
	if (!pool->threads)
		return (false);
	pool->queue = task_queue_create(THREAD_POOL_QUEUE_SIZE);
	if (!pool->queue)
	{
		free(pool->threads);
		return (false);
	}
	return (true);
}

static void	init_pool_data(t_thread_pool *pool, const int thread_count)
{
	pool->thread_count = thread_count;
	pool->shutdown = false;
	pthread_mutex_init(&pool->pool_mutex, NULL);
}

static bool	create_worker_threads(t_thread_pool *pool)
{
	int	i;

	i = 0;
	while (i < pool->thread_count)
	{
		if (pthread_create(&pool->threads[i], NULL, worker_thread, pool) != 0)
			return (false);
		i++;
	}
	return (true);
}

t_thread_pool	*thread_pool_create(int thread_count)
{
	t_thread_pool	*pool;

	thread_count = validate_thread_count(thread_count);
	pool = malloc(sizeof(t_thread_pool));
	if (!pool)
		return (NULL);
	if (!init_pool_memory(pool, thread_count))
	{
		free(pool);
		return (NULL);
	}
	init_pool_data(pool, thread_count);
	if (!create_worker_threads(pool))
	{
		thread_pool_destroy(pool);
		return (NULL);
	}
	return (pool);
}
