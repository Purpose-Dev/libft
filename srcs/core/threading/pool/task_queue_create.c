/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_queue_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:51:52 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/15 00:01:14 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/threading/thread_pool.h"

static int	validate_queue_size(const int max_size)
{
	if (max_size <= 0)
		return (THREAD_POOL_QUEUE_SIZE);
	return (max_size);
}

static void	init_queue_data(t_task_queue *queue, const int max_size)
{
	queue->head = NULL;
	queue->tail = NULL;
	queue->count = 0;
	queue->max_size = max_size;
}

static void	init_queue_mutex(t_task_queue *queue)
{
	pthread_mutex_init(&queue->mutex, NULL);
	pthread_cond_init(&queue->not_empty, NULL);
	pthread_cond_init(&queue->not_full, NULL);
}

t_task_queue	*task_queue_create(int max_size)
{
	t_task_queue	*queue;

	max_size = validate_queue_size(max_size);
	queue = malloc(sizeof(t_task_queue));
	if (!queue)
		return (NULL);
	init_queue_data(queue, max_size);
	init_queue_mutex(queue);
	return (queue);
}
