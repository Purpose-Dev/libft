/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 20:01:01 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/11/05 09:59:16 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_io.h"

int	ft_fputc(const int c, t_ft_file *stream)
{
	unsigned char	ch;

	if (!stream)
		return (FT_EOF);
	ch = (unsigned char)c;
	if (stream->buffer_pos >= stream->buffer_size)
	{
		if (ft_fflush(stream) != 0)
			return (FT_EOF);
	}
	stream->buffer[stream->buffer_pos++] = (char)ch;
	return (ch);
}
