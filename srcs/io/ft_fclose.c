/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fclose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:03:07 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/19 05:17:39 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_io.h"

int	ft_fclose(t_ft_file *stream)
{
	int	result;

	if (!stream)
		return (FT_EOF);
	result = close(stream->fd);
	free(stream->buffer);
	free(stream);
	if (result == -1)
		return (FT_EOF);
	return (0);
}
