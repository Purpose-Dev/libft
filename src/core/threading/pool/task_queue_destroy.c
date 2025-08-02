/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   task_queue_destroy.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:51:59 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/14 23:56:55 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/threading/thread_pool.h"

static void	free_all_tasks(const t_task_queue *queue)
{
	t_task	*current;
	t_task	*next;

	current = queue->head;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
}

void	task_queue_destroy(t_task_queue *queue)
{
	if (!queue)
		return ;
	pthread_mutex_lock(&queue->mutex);
	free_all_tasks(queue);
	pthread_mutex_unlock(&queue->mutex);
	pthread_mutex_destroy(&queue->mutex);
	pthread_cond_destroy(&queue->not_empty);
	pthread_cond_destroy(&queue->not_full);
	free(queue);
}
