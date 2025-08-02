/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_pool.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/14 15:42:37 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/14 22:34:13 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef THREAD_POOL_H
# define THREAD_POOL_H

# include <pthread.h>
# include <stdbool.h>
# include <stdlib.h>

# define THREAD_POOL_DEFAULT_SIZE 4
# define THREAD_POOL_MAX_SIZE 16
# define THREAD_POOL_QUEUE_SIZE 256

typedef struct s_task
{
	void			(*function)(void *);
	void			*arg;
	struct s_task	*next;
}	t_task;

typedef struct s_task_queue
{
	t_task			*head;
	t_task			*tail;
	int				count;
	int				max_size;
	pthread_mutex_t	mutex;
	pthread_cond_t	not_empty;
	pthread_cond_t	not_full;
}	t_task_queue;

typedef struct s_thread_pool
{
	pthread_mutex_t	pool_mutex;
	pthread_t		*threads;
	t_task_queue	*queue;
	int				thread_count;
	bool			shutdown;
	char			padding[3];
}	t_thread_pool;

t_thread_pool	*thread_pool_create(int thread_count);
void			thread_pool_destroy(t_thread_pool *pool);
bool			thread_pool_add_task(t_thread_pool *pool,
					void (*function)(void *), void *arg);
void			thread_pool_wait(t_thread_pool *pool);
int				thread_pool_pending_tasks(t_thread_pool *pool);

t_task_queue	*task_queue_create(int max_size);
void			task_queue_destroy(t_task_queue *queue);
bool			task_queue_push(t_task_queue *queue, t_task *task);
t_task			*task_queue_pop(t_task_queue *queue);
bool			task_queue_is_empty(t_task_queue *queue);

void			*worker_thread(void *arg);

#endif // THREAD_POOL_H
