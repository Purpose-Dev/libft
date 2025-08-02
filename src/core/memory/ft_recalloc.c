/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 10:22:51 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/21 10:40:20 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include "core/memory/ft_memory.h"

void	*ft_recalloc(void *ptr, const size_t size)
{
	size_t	old_size;
	void	*new_ptr;

	if (!ptr)
		return (malloc(size));
	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	old_size = malloc_usable_size(ptr);
	if (size <= old_size)
		return (ptr);
	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	ft_memset(ft_mempcpy(new_ptr, ptr, old_size), 0, old_size - size);
	free(ptr);
	return (new_ptr);
}
