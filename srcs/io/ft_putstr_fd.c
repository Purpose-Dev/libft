/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:46:01 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/18 11:45:54 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string/ft_string.h"
#include "io/ft_io.h"

#ifdef _WIN32

void	ft_putstr_fd(const char *s, const int fd)
{
	if (!s)
		return ;
	_write(fd, s, ft_strlen(s));
}
#else

void	ft_putstr_fd(const char *s, const int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
#endif
