/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_pool_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 16:51:34 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/14 23:47:23 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "core/threading/thread_pool.h"

void	thread_pool_wait(t_thread_pool *pool)
{
	if (!pool)
		return ;
	while (!task_queue_is_empty(pool->queue))
		usleep(1000);
}
