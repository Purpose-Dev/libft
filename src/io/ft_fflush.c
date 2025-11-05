/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fflush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:00:29 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/11/05 09:54:35 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "io/ft_io.h"

int	ft_fflush(t_ft_file *stream)
{
	ssize_t	written;

	if (!stream)
		return (-1);
	if (stream->buffer_pos == 0)
		return (0);
	written = write(stream->fd, stream->buffer, stream->buffer_pos);
	if (written < 0)
	{
		stream->error = 1;
		return (FT_EOF);
	}
	stream->buffer_pos = 0;
	return (0);
}
