/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fopen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 05:00:52 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/10/26 19:57:02 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "core/string/ft_string.h"
#include "io/ft_io.h"

static int	get_flags(const char *mode)
{
	if (ft_strcmp(mode, "r") == 0 || ft_strcmp(mode, "rb") == 0)
		return (O_RDONLY);
	if (ft_strcmp(mode, "w") == 0 || ft_strcmp(mode, "wb") == 0)
		return (O_WRONLY | O_CREAT | O_TRUNC);
	if (ft_strcmp(mode, "a") == 0 || ft_strcmp(mode, "ab") == 0)
		return (O_WRONLY | O_CREAT | O_APPEND);
	if (ft_strcmp(mode, "r+") == 0 || ft_strcmp(mode, "r+b") == 0
		|| ft_strcmp(mode, "rb+") == 0)
		return (O_RDWR);
	if (ft_strcmp(mode, "w+") == 0 || ft_strcmp(mode, "w+b") == 0
		|| ft_strcmp(mode, "wb+") == 0)
		return (O_RDWR | O_CREAT | O_TRUNC);
	if (ft_strcmp(mode, "a+") == 0 || ft_strcmp(mode, "a+b") == 0
		|| ft_strcmp(mode, "ab+") == 0)
		return (O_RDWR | O_CREAT | O_APPEND);
	return (-1);
}

static t_ft_file	*init_file_struct(const int fd)
{
	t_ft_file	*file;

	file = malloc(sizeof(t_ft_file));
	if (!file)
		return (NULL);
	file->buffer = malloc(FT_BUFFER_SIZE);
	if (!file->buffer)
	{
		free(file);
		return (NULL);
	}
	file->fd = fd;
	file->buffer_size = FT_BUFFER_SIZE;
	file->buffer_pos = 0;
	file->buffer_len = 0;
	file->eof = 0;
	file->error = 0;
	return (file);
}

t_ft_file	*ft_fopen(const char *filename, const char *mode)
{
	int			fd;
	int			flags;
	t_ft_file	*file;

	if (!filename || !mode)
		return (NULL);
	flags = get_flags(mode);
	if (flags == -1)
		return (NULL);
	fd = open(filename, flags, 0644);
	if (fd == -1)
		return (NULL);
	file = init_file_struct(fd);
	if (!file)
	{
		close(fd);
		return (NULL);
	}
	return (file);
}
