/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_queue_pop.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:52:09 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/15 00:07:38 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/threading/thread_pool.h"

static void	wait_for_task(t_task_queue *queue)
{
	while (queue->count == 0)
		pthread_cond_wait(&queue->not_empty, &queue->mutex);
}

static t_task	*remove_task_from_queue(t_task_queue *queue)
{
	t_task	*task;

	task = queue->head;
	queue->head = task->next;
	if (!queue->head)
		queue->tail = NULL;
	queue->count--;
	return (task);
}

t_task	*task_queue_pop(t_task_queue *queue)
{
	t_task	*task;

	if (!queue)
		return (NULL);
	pthread_mutex_lock(&queue->mutex);
	wait_for_task(queue);
	task = remove_task_from_queue(queue);
	pthread_cond_signal(&queue->not_full);
	pthread_mutex_unlock(&queue->mutex);
	return (task);
}

bool	task_queue_is_empty(t_task_queue *queue)
{
	bool	empty;

	if (!queue)
		return (true);
	pthread_mutex_lock(&queue->mutex);
	empty = (queue->count == 0);
	pthread_mutex_unlock(&queue->mutex);
	return (empty);
}
