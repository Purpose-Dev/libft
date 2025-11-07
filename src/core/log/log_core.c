/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_core.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:06:54 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/11/07 09:26:07 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "core/log/log.h"
#include "core/log/log_internal.h"
#include "core/memory/ft_memory.h"

t_logger	g_logger;

void	log_init(void)
{
	ft_memset(&g_logger, 0, sizeof(t_logger));
	pthread_mutex_init(&g_logger.mutex, NULL);
	g_logger.global_min_level = LOG_DEBUG;
	g_logger.is_quiet = false;
	g_logger.use_color = (isatty(STDOUT_FILENO) != 0);
	g_logger.sink_count = 0;
	log_add_sink(ft_stderr(), LOG_WARN);
}

void	log_destroy(void)
{
	pthread_mutex_destroy(&g_logger.mutex);
}

int	log_add_sink(t_ft_file *stream, const t_log_level min_level)
{
	if (!stream)
		return (-1);
	pthread_mutex_lock(&g_logger.mutex);
	if (g_logger.sink_count >= MAX_LOG_SINKS)
	{
		pthread_mutex_unlock(&g_logger.mutex);
		return (-1);
	}
	g_logger.sinks[g_logger.sink_count].stream = stream;
	g_logger.sinks[g_logger.sink_count].min_level = min_level;
	g_logger.sinks[g_logger.sink_count].use_color = g_logger.use_color;
	g_logger.sink_count++;
	pthread_mutex_unlock(&g_logger.mutex);
	return (0);
}
