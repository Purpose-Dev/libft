/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:45:54 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 16:55:36 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_io.h"

#ifdef _WIN32

void	ft_putchar_fd(const char c, const int fd)
{
	_write(fd, &c, 1);
}
#else

void	ft_putchar_fd(const char c, const int fd)
{
	write(fd, &c, 1);
}
#endif
