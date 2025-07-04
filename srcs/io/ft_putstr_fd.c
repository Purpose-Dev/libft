/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:46:01 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/04 18:49:20 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_io.h"
#include "core/string/ft_string.h"

void	ft_putstr_fd(char *s, const int fd)
{
	if (!s)
		return ;
#ifdef _WIN32
	_write(fd, s, ft_strlen(s));
#else
	write(fd, s, ft_strlen(s));
#endif
}
