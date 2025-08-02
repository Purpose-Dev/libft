/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_queue_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:52:04 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/15 00:13:23 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/threading/thread_pool.h"

static void	wait_for_space(t_task_queue *queue)
{
	while (queue->count >= queue->max_size)
		pthread_cond_wait(&queue->not_full, &queue->mutex);
}

static void	add_task_to_queue(t_task_queue *queue, t_task *task)
{
	if (queue->tail)
	{
		queue->tail->next = task;
		queue->tail = task;
	}
	else
	{
		queue->head = task;
		queue->tail = task;
	}
	queue->count++;
}

bool	task_queue_push(t_task_queue *queue, t_task *task)
{
	if (!queue || !task)
		return (false);
	pthread_mutex_lock(&queue->mutex);
	wait_for_space(queue);
	add_task_to_queue(queue, task);
	pthread_cond_signal(&queue->not_empty);
	pthread_mutex_unlock(&queue->mutex);
	return (true);
}
