/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:02:20 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/11/05 09:54:45 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "io/ft_io.h"

long	ft_ftell(t_ft_file *stream)
{
	long	pos;

	if (!stream)
		return (-1L);
	pos = lseek(stream->fd, 0, SEEK_CUR);
	if (pos < 0)
	{
		stream->error = 1;
		return (-1L);
	}
	return (pos - (long)stream->buffer_len + (long)stream->buffer_pos);
}
