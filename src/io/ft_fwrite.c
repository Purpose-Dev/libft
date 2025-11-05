/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fwrite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 19:46:42 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/11/05 09:54:28 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "io/ft_io.h"

ssize_t	ft_fwrite(const void *ptr, const size_t size, const size_t count,
					t_ft_file *stream)
{
	const char	*data;
	size_t		total_bytes;
	ssize_t		written;

	if (!ptr || !stream || size == 0 || count == 0)
		return (0);
	total_bytes = size * count;
	data = (const char *)ptr;
	written = write(stream->fd, data, total_bytes);
	if (written < 0)
	{
		stream->error = 1;
		return (-1);
	}
	return (written);
}
