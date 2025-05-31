/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallocarray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:03:12 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/31 16:07:31 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory/ft_memory.h"

void	*ft_reallocarray(void *ptr, size_t nmemb, size_t size)
{
	size_t	total_size;

	if (nmemb == 0 || size == 0)
		return (ft_realloc(ptr, 0));
	if (nmemb > SIZE_MAX / size)
	{
		errno = ENOMEM;
		return (NULL);
	}
	total_size = nmemb * size;
	if (total_size > PTRDIFF_MAX)
	{
		errno = ENOMEM;
		return (NULL);
	}
	return (ft_realloc(ptr, total_size));
}
