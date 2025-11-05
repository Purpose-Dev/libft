/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fgetc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:00:26 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/11/05 09:53:30 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "io/ft_io.h"

static int	fill_buffer(t_ft_file *stream)
{
	ssize_t	bytes_read;

	bytes_read = read(stream->fd, stream->buffer, stream->buffer_size);
	if (bytes_read <= 0)
	{
		if (bytes_read == 0)
			stream->eof = 1;
		else
			stream->error = 1;
		return (-1);
	}
	stream->buffer_len = (size_t)bytes_read;
	stream->buffer_pos = 0;
	return (0);
}

int	ft_fgetc(t_ft_file *stream)
{
	unsigned char	c;

	if (!stream || stream->error || stream->eof)
		return (FT_EOF);
	if (stream->buffer_pos >= stream->buffer_len)
	{
		if (fill_buffer(stream) == -1)
			return (FT_EOF);
	}
	c = (unsigned char)stream->buffer[stream->buffer_pos];
	stream->buffer_pos++;
	return ((int)c);
}
