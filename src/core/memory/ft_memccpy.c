/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 22:33:28 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/07 01:10:06 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/memory/ft_memory.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr = src;
	const unsigned char	char_c = (unsigned char)c;
	size_t				i;

	dest_ptr = (unsigned char *)dest;
	i = 0;
	while (i < n)
	{
		dest_ptr[i] = src_ptr[i];
		if (src_ptr[i] == char_c)
			return (dest_ptr + i + 1);
		i++;
	}
	return (NULL);
}
