/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:57:07 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/11/05 09:54:19 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdlib.h"
#include "io/ft_io.h"

static int			g_cleanup_registered = 0;

static t_ft_file	g_stdin_file = {NULL, 0, 0, 0, 0, 0, 0, {0}};
static t_ft_file	g_stdout_file = {NULL, 0, 0, 0, 1, 0, 0, {0}};
static t_ft_file	g_stderr_file = {NULL, 0, 0, 0, 2, 0, 0, {0}};

static void	cleanup_streams(void)
{
	if (g_stdout_file.buffer)
	{
		ft_fflush(&g_stdout_file);
		free(g_stdout_file.buffer);
		g_stdout_file.buffer = NULL;
	}
	if (g_stderr_file.buffer)
	{
		ft_fflush(&g_stderr_file);
		free(g_stderr_file.buffer);
		g_stderr_file.buffer = NULL;
	}
	if (g_stdin_file.buffer)
	{
		free(g_stdin_file.buffer);
		g_stdin_file.buffer = NULL;
	}
}

static int	init_std_file(t_ft_file *file)
{
	if (file->buffer)
		return (0);
	file->buffer = malloc(1024);
	if (!file->buffer)
		return (-1);
	file->buffer_size = 1024;
	file->buffer_pos = 0;
	file->buffer_len = 0;
	file->eof = 0;
	file->error = 0;
	if (!g_cleanup_registered)
	{
		ft_atexit(cleanup_streams);
		g_cleanup_registered = 1;
	}
	return (0);
}

t_ft_file	*ft_stdin(void)
{
	if (init_std_file(&g_stdin_file) == -1)
		return (NULL);
	return (&g_stdin_file);
}

t_ft_file	*ft_stdout(void)
{
	if (init_std_file(&g_stdout_file) == -1)
		return (NULL);
	return (&g_stdout_file);
}

t_ft_file	*ft_stderr(void)
{
	if (init_std_file(&g_stderr_file) == -1)
		return (NULL);
	return (&g_stderr_file);
}
