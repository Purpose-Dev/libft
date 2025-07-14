/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_pool_destroy.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:51:17 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/14 22:23:55 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/threading/thread_pool.h"

static void	signal_shutdown(t_thread_pool *pool)
{
	pthread_mutex_lock(&pool->pool_mutex);
	pool->shutdown = true;
	pthread_mutex_unlock(&pool->pool_mutex);
	pthread_cond_broadcast(&pool->queue->not_empty);
}

static void	join_all_threads(const t_thread_pool *pool)
{
	int	i;

	i = 0;
	while (i < pool->thread_count)
	{
		pthread_join(pool->threads[i], NULL);
		i++;
	}
}

void	thread_pool_destroy(t_thread_pool *pool)
{
	if (!pool)
		return ;
	signal_shutdown(pool);
	join_all_threads(pool);
	task_queue_destroy(pool->queue);
	pthread_mutex_destroy(&pool->pool_mutex);
	free(pool->threads);
	free(pool);
}
