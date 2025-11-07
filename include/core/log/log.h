/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 08:53:41 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/11/07 09:27:08 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOG_H
# define LOG_H

# include <stdbool.h>

# include "io/ft_io.h"

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

void	log_init(void);
void	log_destroy(void);

int		log_add_sink(t_ft_file *stream, t_log_level min_level);

void	log_set_level(t_log_level min_level);
void	log_set_quiet(bool quiet);
void	log_set_color(bool enable);

void	ft_log(t_log_level level, const char *module, const char *format, ...);
void	log_debug(const char *module, const char *format, ...);
void	log_error(const char *module, const char *format, ...);
void	log_fatal(const char *module, const char *format, ...);
void	log_info(const char *module, const char *format, ...);
void	log_warn(const char *module, const char *format, ...);

#endif // LOG_H
