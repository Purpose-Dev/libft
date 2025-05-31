/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:39:25 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/12 22:41:57 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory/ft_memory.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total_size;
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		ptr = malloc(0);
		if (!ptr)
			errno = ENOMEM;
		return (ptr);
	}
	if (nmemb > SIZE_MAX / size)
		return (errno = ENOMEM, NULL);
	total_size = nmemb * size;
	if (total_size > PTRDIFF_MAX)
		return (errno = ENOMEM, NULL);
	ptr = (void *)malloc(nmemb * size);
	if (!ptr)
		return (errno = ENOMEM, NULL);
	ft_bzero(ptr, (nmemb * size));
	return (ptr);
}
