/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:46:01 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/31 17:33:52 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_io.h"
#include "string/ft_string.h"

void	ft_putstr_fd(char *s, const int fd)
{
	if (!s)
		return ;
	write(fd, s, ft_strlen(s));
}
