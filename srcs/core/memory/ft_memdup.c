/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 02:56:10 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/05 03:09:36 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/memory/ft_memory.h"

void	*ft_memdup(const void *src, const size_t n)
{
	void	*ptr;

	if (!src)
		return (NULL);
	ptr = malloc(n);
	if (!ptr)
		return (NULL);
	if (n > 0)
		ft_memcpy(ptr, src, n);
	return (ptr);
}
