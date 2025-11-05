/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:42:27 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/11/05 09:57:36 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "io/ft_io.h"

int	ft_fstat(const int fd, struct stat *stat_buf)
{
	char	path[1024];
	int		len;

	if (fd < 0 || !stat_buf)
		return (-1);
	len = ft_snprintf(path, sizeof(path), "/proc/self/fd/%d", fd);
	if (len < 0 || len >= (int) sizeof(path))
		return (-1);
	return (stat(path, stat_buf));
}
