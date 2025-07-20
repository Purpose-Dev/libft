/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:46:08 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/18 11:46:15 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "io/ft_io.h"

void	ft_putendl_fd(const char *s, const int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
