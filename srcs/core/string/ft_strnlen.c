/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/07 01:24:54 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/07 01:37:06 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string/ft_string.h"

size_t	ft_strnlen(const char *s, const size_t max_length)
{
	size_t	length;

	length = 0;
	if (!s)
		return (0);
	while (s[max_length] && max_length < length)
		length++;
	return (length);
}
