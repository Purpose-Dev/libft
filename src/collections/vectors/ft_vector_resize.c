/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_resize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 03:45:46 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/12 10:37:32 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "collections/vectors/vector.h"
#include "core/memory/ft_memory.h"

t_result	ft_vector_resize(t_vector *vec, const size_t size)
{
	t_value	*save_ptr;
	t_value	*new_data;
	size_t	real_offset;

	if (size <= vec->capacity)
		return (RESULT_ERROR);
	new_data = malloc(size * sizeof(t_value));
	if (!new_data)
		return (RESULT_ERROR);
	real_offset = vec->offset % vec->capacity;
	save_ptr = ft_mempcpy(new_data, vec->data + real_offset,
			sizeof(t_value) * (vec->capacity - real_offset));
	ft_memcpy(save_ptr, vec->data, sizeof(t_value) * real_offset);
	free(vec->data);
	vec->data = new_data;
	vec->capacity = size;
	vec->offset = 0;
	return (RESULT_OK);
}
