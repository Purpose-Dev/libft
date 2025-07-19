/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:57:07 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 00:36:01 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_io.h"

static t_ft_file	g_stdin_file = {NULL, 0, 0, 0, STDIN_FILENO, 0, 0, {0}};
static t_ft_file	g_stdout_file = {NULL, 0, 0, 0, STDOUT_FILENO, 0, 0, {0}};
static t_ft_file	g_stderr_file = {NULL, 0, 0, 0, STDERR_FILENO, 0, 0, {0}};

static int	init_std_file(t_ft_file *file)
{
	if (file->buffer)
		return (0);
	file->buffer = malloc(FT_BUFSIZ);
	if (!file->buffer)
		return (-1);
	file->buffer_size = FT_BUFSIZ;
	file->buffer_pos = 0;
	file->buffer_len = 0;
	file->eof = 0;
	file->error = 0;
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
