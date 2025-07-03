/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 19:25:32 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/03 19:37:26 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/errors/ft_errno.h"
#include "core/string/ft_string.h"

ssize_t	ft_strlen_s(const char *str)
{
	auto ssize_t len = 0;
	if (!str)
	{
		errno = ESNULLP;
		return (-1);
	}
	while (str[len])
		len++;
	return (len);
}
