/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:07:36 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/11/17 14:36:53 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/log/log.h"
#include "core/log/log_internal.h"
#include "core/memory/ft_memory.h"
#include "io/ft_printf.h"

typedef struct s_log
{
	t_log_sink	*sink;
	char		*module;
	t_log_level	level;
	char		padding[4];
}	t_log;

static inline void	init_log(t_log *log, t_log_sink *sink,
				const t_log_level level, char *module)
{
	ft_bzero(log, sizeof(t_log));
	log->sink = sink;
	log->level = level;
	log->module = module;
}

static void	log_write_one(const t_log log, const char *format, va_list args)
{
	va_list	copy;
	bool	use_color;

	use_color = (g_logger.use_color && log.sink->use_color);
	if (use_color)
		ft_fprintf(log.sink->stream, "%s", get_level_color(log.level));
	ft_fprintf(log.sink->stream, "[%s]", get_level_string(log.level));
	if (use_color)
		ft_fprintf(log.sink->stream, "%s", CLR_RESET);
	if (log.module)
		ft_fprintf(log.sink->stream, " (%s)", log.module);
	ft_fprintf(log.sink->stream, ": ");
	va_copy(copy, args);
	ft_vfprintf(log.sink->stream, format, copy);
	va_end(copy);
	ft_fprintf(log.sink->stream, "\n");
}

void	ft_vlog(const t_log_level level, const char *module,
			const char *format, va_list args)
{
	t_log	log;
	int		i;

	pthread_mutex_lock(&g_logger.mutex);
	if (g_logger.is_quiet || level < g_logger.global_min_level)
	{
		pthread_mutex_unlock(&g_logger.mutex);
		return ;
	}
	i = 0;
	while (i < g_logger.sink_count)
	{
		if (g_logger.sinks[i].stream
			&& level >= g_logger.sinks[i].min_level)
		{
			init_log(&log, &g_logger.sinks[i], level,
				(char *)(intptr_t)module);
			log_write_one(log, format, args);
		}
		i++;
	}
	pthread_mutex_unlock(&g_logger.mutex);
}

void	ft_log(const t_log_level level, const char *module, const char *format,
				...)
{
	va_list	args;

	va_start(args, format);
	ft_vlog(level, module, format, args);
	va_end(args);
}
