/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 03:11:32 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 14:10:43 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/memory/ft_memory.h"

void	*ft_memrchr(const void *s, const int c, size_t n)
{
	unsigned char		*c_ptr;
	const unsigned char	char_to_find = (unsigned char)c;

	c_ptr = (unsigned char *)(intptr_t)s;
	while (n > 0)
	{
		n--;
		if (c_ptr[n] == char_to_find)
			return ((void *)(c_ptr + n));
	}
	return (NULL);
}
