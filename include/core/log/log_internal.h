/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:16:36 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/11/17 14:37:04 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_INTERNAL_H
# define LOG_INTERNAL_H

# include <pthread.h>

# include "log.h"

# ifndef MAX_LOG_SINKS
#  define MAX_LOG_SINKS 16
# endif // MAX_LOG_SINKS

# define CLR_RESET		"\x1b[0m"
# define CLR_DIM		"\x1b[2m"
# define CLR_RED		"\x1b[31m"
# define CLR_GREEN		"\x1b[32m"
# define CLR_YELLOW		"\x1b[33m"
# define CLR_BLUE		"\x1b[94m"
# define CLR_MAGENTA	"\x1b[35m"

typedef struct s_logger
{
	t_log_sink		sinks[MAX_LOG_SINKS];
	pthread_mutex_t	mutex;
	t_log_level		global_min_level;
	int				sink_count;
	bool			is_quiet;
	bool			use_color;
	char			padding[6];
}	t_logger;

extern t_logger	g_logger;

inline const char	*get_level_string(const t_log_level level)
{
	if (level == LOG_DEBUG)
		return ("DEBUG");
	if (level == LOG_ERROR)
		return ("ERROR");
	if (level == LOG_FATAL)
		return ("FATAL");
	if (level == LOG_INFO)
		return ("INFO ");
	if (level == LOG_WARN)
		return ("WARN ");
	return ("?????");
}

inline const char	*get_level_color(const t_log_level level)
{
	if (level == LOG_DEBUG)
		return (CLR_BLUE);
	if (level == LOG_ERROR)
		return (CLR_RED);
	if (level == LOG_FATAL)
		return (CLR_MAGENTA);
	if (level == LOG_INFO)
		return (CLR_GREEN);
	if (level == LOG_WARN)
		return (CLR_YELLOW);
	return (CLR_RESET);
}

#endif // LOG_INTERNAL_H
