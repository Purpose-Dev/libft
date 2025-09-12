/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_unshift.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:45:17 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/12 10:59:16 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/vectors/vector.h"

static inline size_t	scale_fast(const size_t capacity)
{
	return (capacity + (capacity >> 1));
}

t_result	ft_vector_unshift(t_vector *vec, const t_value value)
{
	if (value.type == TYPE_UNDEFINED)
		return (RESULT_OK);
	if (vec->length == vec->capacity
		&& ft_vector_resize(vec, scale_fast(vec->capacity)) != RESULT_OK)
		return (RESULT_ERROR);
	vec->length++;
	vec->offset--;
	if (vec->offset == -1UL)
		vec->offset = vec->capacity - 1;
	vec->data[vec->offset % vec->capacity] = value;
	return (RESULT_OK);
}
