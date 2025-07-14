/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_pool_tasks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:51:28 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/14 23:44:32 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/threading/thread_pool.h"

static bool	is_pool_shutdown(t_thread_pool *pool)
{
	bool	shutdown;

	pthread_mutex_lock(&pool->pool_mutex);
	shutdown = pool->shutdown;
	pthread_mutex_unlock(&pool->pool_mutex);
	return (shutdown);
}

static t_task	*create_task(void (*function)(void *), void *arg)
{
	t_task	*task;

	task = malloc(sizeof(t_task));
	if (!task)
		return (NULL);
	task->function = function;
	task->arg = arg;
	task->next = NULL;
	return (task);
}

bool	thread_pool_add_task(t_thread_pool *pool, void (*function)(void *),
		void *arg)
{
	t_task	*task;

	if (!pool || !function)
		return (false);
	if (is_pool_shutdown(pool))
		return (false);
	task = create_task(function, arg);
	if (!task)
		return (false);
	return (task_queue_push(pool->queue, task));
}

int	thread_pool_pending_tasks(t_thread_pool *pool)
{
	int	count;

	if (!pool)
		return (0);
	pthread_mutex_lock(&pool->queue->mutex);
	count = pool->queue->count;
	pthread_mutex_unlock(&pool->queue->mutex);
	return (count);
}
