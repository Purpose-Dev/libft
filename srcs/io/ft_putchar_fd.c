/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:45:54 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/04 18:49:56 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_io.h"

void	ft_putchar_fd(const char c, const int fd)
{
#ifdef _WIN32
	_write(fd, &c, 1);
#else
	write(fd, &c, 1);
#endif
}
