/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 02:10:18 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/03 18:49:51 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>
#include "core/memory/ft_memory.h"

void	*ft_realloc(void *ptr, const size_t size)
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
	if (old_size == size) return (ptr);
	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	if (old_size > size)
		old_size = size;
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}
