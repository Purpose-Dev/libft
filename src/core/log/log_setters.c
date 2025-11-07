/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log_setters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 09:07:19 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/11/07 09:30:29 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/log/log.h"
#include "core/log/log_internal.h"

void	log_set_level(const t_log_level min_level)
{
	pthread_mutex_lock(&g_logger.mutex);
	g_logger.global_min_level = min_level;
	pthread_mutex_unlock(&g_logger.mutex);
}

void	log_set_quiet(const bool quiet)
{
	pthread_mutex_lock(&g_logger.mutex);
	g_logger.is_quiet = quiet;
	pthread_mutex_unlock(&g_logger.mutex);
}

void	log_set_color(const bool enable)
{
	pthread_mutex_lock(&g_logger.mutex);
	g_logger.use_color = enable;
	pthread_mutex_unlock(&g_logger.mutex);
}
