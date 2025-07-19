/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getline.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 04:22:14 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/19 05:35:54 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_io.h"

#define BUFFER_SIZE 1024

static int	init_buffer(char **line_ptr, size_t *n)
{
	if (!*line_ptr || *n == 0)
	{
		*n = BUFFER_SIZE;
		*line_ptr = malloc(*n);
		if (!*line_ptr)
			return (-1);
	}
	return (0);
}

static char	*expand_buffer(char *line_ptr, size_t *n, size_t needed)
{
	char	*new_buffer;
	size_t	i;

	needed *= 2;
	new_buffer = malloc(needed);
	if (!new_buffer)
		return (NULL);
	i = 0;
	while (i < *n && line_ptr[i])
	{
		new_buffer[i] = line_ptr[i];
		i++;
	}
	new_buffer[i] = '\0';
	free(line_ptr);
	*n = needed;
	return (new_buffer);
}

static ssize_t	read_line_from_stream(char **line_ptr, size_t *n,
										t_ft_file *stream)
{
	auto int c;
	auto size_t pos = 0;
	while (1)
	{
		c = ft_fgetc(stream);
		if (c == FT_EOF)
		{
			if (pos == 0)
				return (-1);
			break ;
		}
		if (pos + 1 >= *n)
		{
			*line_ptr = expand_buffer(*line_ptr, n, pos + BUFFER_SIZE);
			if (!*line_ptr)
				return (-1);
		}
		(*line_ptr)[pos] = (char)c;
		pos++;
		if (c == '\n')
			break ;
	}
	(*line_ptr)[pos] = '\0';
	return ((ssize_t)pos);
}

ssize_t	ft_getline(char **line_ptr, size_t *n, t_ft_file *stream)
{
	if (!line_ptr || !stream)
		return (-1);
	if (init_buffer(line_ptr, n) == -1)
		return (-1);
	return (read_line_from_stream(line_ptr, n, stream));
}
