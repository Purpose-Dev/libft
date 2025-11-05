/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:57:57 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/11/05 09:53:54 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "io/ft_io.h"

static size_t	read_from_buffer(t_ft_file *stream, char *dest,
									const size_t bytes_needed)
{
	size_t	available;
	size_t	to_copy;
	size_t	i;

	available = stream->buffer_len - stream->buffer_pos;
	to_copy = bytes_needed;
	if (to_copy > available)
		to_copy = available;
	i = 0;
	while (i < to_copy)
	{
		dest[i] = stream->buffer[stream->buffer_pos + i];
		i++;
	}
	stream->buffer_pos += to_copy;
	return (to_copy);
}

static int	fill_buffer(t_ft_file *stream)
{
	ssize_t	bytes_read;

	if (stream->buffer_pos >= stream->buffer_len)
	{
		bytes_read = read(stream->fd, stream->buffer, stream->buffer_size);
		if (bytes_read <= 0)
		{
			if (bytes_read == 0)
				stream->eof = 1;
			else
				stream->error = 1;
			return (0);
		}
		stream->buffer_len = (size_t)bytes_read;
		stream->buffer_pos = 0;
	}
	return (1);
}

static size_t	fill_and_read(t_ft_file *stream, char *dest,
								size_t bytes_needed)
{
	size_t	total_read;
	size_t	chunk_read;

	total_read = 0;
	while (bytes_needed > 0)
	{
		if (!fill_buffer(stream))
			break ;
		chunk_read = read_from_buffer(stream, dest + total_read, bytes_needed);
		total_read += chunk_read;
		bytes_needed -= chunk_read;
	}
	return (total_read);
}

size_t	ft_fread(void *ptr, const size_t size, const size_t count,
					t_ft_file *stream)
{
	size_t	total_bytes;
	size_t	bytes_read;
	size_t	elements_read;

	if (!ptr || size == 0 || count == 0 || !stream)
		return (0);
	if (stream->error || stream->eof)
		return (0);
	total_bytes = size * count;
	bytes_read = fill_and_read(stream, (char *)ptr, total_bytes);
	elements_read = bytes_read / size;
	return (elements_read);
}
