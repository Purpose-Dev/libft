/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 02:10:18 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/05/31 23:05:20 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/memory/ft_memory.h"

static size_t	ptr_size(const void *ptr)
{
	const char	*c_ptr = ptr;
	size_t		i;

	i = 0;
	while (*c_ptr++ && i < SIZE_MAX - 1)
		i++;
	return (i);
}

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
	if (size > SIZE_MAX)
		return (NULL);
	old_size = ptr_size(ptr);
	if (old_size == size)
		return (ptr);
	new_ptr = malloc(size);
	if (!new_ptr)
		return (NULL);
	if (old_size < size)
		old_size = size;
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}
