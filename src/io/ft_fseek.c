/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fseek.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:02:36 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/11/05 09:54:56 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "io/ft_io.h"

int	ft_fseek(t_ft_file *stream, const long offset, const int whence)
{
	if (!stream)
		return (-1);
	if (ft_fflush(stream) != 0)
		return (-1);
	if (lseek(stream->fd, offset, whence) < 0)
	{
		stream->error = 1;
		return (-1);
	}
	stream->buffer_pos = 0;
	stream->buffer_len = 0;
	stream->eof = 0;
	return (0);
}
