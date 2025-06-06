/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 03:11:32 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/07 01:04:56 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/memory/ft_memory.h"

void	*ft_memrchr(const void *s, const int c, size_t n)
{
	const unsigned char	*c_ptr = s;
	const unsigned char	char_to_find = (unsigned char)c;

	while (n > 0)
	{
		n--;
		if (c_ptr[n] == char_to_find)
			return ((void *)(c_ptr + n));
	}
	return (NULL);
}
