/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 22:39:25 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/06/04 03:51:29 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/memory/ft_memory.h"

void	*ft_calloc(const size_t nmemb, const size_t size)
{
	size_t	total_size;
	void	*ptr;

	if (nmemb == 0 || size == 0)
	{
		ptr = NULL;
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
