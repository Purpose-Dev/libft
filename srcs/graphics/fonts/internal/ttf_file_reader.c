/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttf_file_reader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:27:01 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 17:44:52 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "core/memory/ft_memory.h"
#include "graphics/fonts/ttf_internal.h"
#include "io/ft_io.h"

static uint8_t	*ttf_read_chunk(t_ft_file *file, uint8_t *data,
		size_t *total_size)
{
	uint8_t	*buffer;
	size_t	bytes_read;

	buffer = malloc(8192);
	if (!buffer)
		return (NULL);
	bytes_read = ft_fread(buffer, 1, 8192, file);
	if (bytes_read > 0)
	{
		data = ft_realloc(data, *total_size + bytes_read);
		if (data)
		{
			ft_memcpy(data + *total_size, buffer, bytes_read);
			*total_size += bytes_read;
		}
	}
	free(buffer);
	return (data);
}

static bool	ttf_should_continue_reading(const uint8_t *data,
		const size_t total_size, t_ft_file *file)
{
	if (!data && total_size > 0)
		return (false);
	if (ft_feof(file))
		return (false);
	return (true);
}

uint8_t	*ttf_read_file_data(const char *filename, size_t *data_size)
{
	t_ft_file	*file;
	uint8_t		*data;
	size_t		total_size;

	file = ft_fopen(filename, "rb");
	if (!file)
		return (NULL);
	data = NULL;
	total_size = 0;
	while (data || total_size == 0)
	{
		data = ttf_read_chunk(file, data, &total_size);
		if (!ttf_should_continue_reading(data, total_size, file))
			break ;
	}
	ft_fclose(file);
	*data_size = total_size;
	return (data);
}
