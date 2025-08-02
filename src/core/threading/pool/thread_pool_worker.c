/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_pool_worker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:51:23 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/14 23:49:03 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/threading/thread_pool.h"

static bool	should_shutdown(t_thread_pool *pool)
{
	bool	shutdown;

	pthread_mutex_lock(&pool->pool_mutex);
	shutdown = pool->shutdown;
	pthread_mutex_unlock(&pool->pool_mutex);
	return (shutdown);
}

static void	execute_task(t_task *task)
{
	task->function(task->arg);
	free(task);
}

void	*worker_thread(void *arg)
{
	t_thread_pool	*pool;
	t_task			*task;

	pool = (t_thread_pool *)arg;
	while (true)
	{
		task = task_queue_pop(pool->queue);
		if (!task)
		{
			if (should_shutdown(pool))
				break ;
			continue ;
		}
		execute_task(task);
	}
	return (NULL);
}
