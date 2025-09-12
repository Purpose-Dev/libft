/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:45:03 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/12 10:55:32 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/vectors/vector.h"

static inline size_t	scale_fast(const size_t capacity)
{
	return (capacity + (capacity >> 1));
}

t_result	ft_vector_push(t_vector *vec, const t_value value)
{
	if (value.type == TYPE_UNDEFINED)
		return (RESULT_OK);
	if (vec->length == vec->capacity
		&& ft_vector_resize(vec, scale_fast(vec->capacity)) != RESULT_OK)
	{
		return (RESULT_ERROR);
	}
	vec->data[(vec->length++ + vec->offset) % vec->capacity] = value;
	return (RESULT_OK);
}
