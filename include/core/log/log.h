/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:53:41 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/11/07 09:14:13 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include <pthread.h>
# include <stdbool.h>

# include "io/ft_io.h"

# ifndef MAX_LOG_SINKS
#  define MAX_LOG_SINKS 16
# endif // MAX_LOG_SINKS

typedef enum e_log_level
{
	LOG_DEBUG,
	LOG_ERROR,
	LOG_FATAL,
	LOG_INFO,
	LOG_WARN,
}	t_log_level;

typedef struct s_log_sink
{
	t_ft_file	*stream;
	t_log_level	min_level;
	bool		use_color;
	char		padding[3];
}	t_log_sink;

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

void	log_init(void);
void	log_destroy(void);

int		log_add_sink(t_ft_file *stream, t_log_level min_level);

void	log_set_level(t_log_level min_level);
void	log_set_quiet(bool quiet);
void	log_set_color(bool enable);

void	log(t_log_level level, const char *module, const char *format, ...);
void	log_debug(const char *module, const char *format, ...);
void	log_error(const char *module, const char *format, ...);
void	log_fatal(const char *module, const char *format, ...);
void	log_info(const char *module, const char *format, ...);
void	log_warn(const char *module, const char *format, ...);

#endif // LOG_H
