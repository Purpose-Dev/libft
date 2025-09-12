/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 03:45:37 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/12 10:38:17 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "collections/vectors/vector.h"

t_result	ft_vector_init(t_vector *vec, const size_t size)
{
	vec->capacity = size;
	vec->length = 0;
	vec->offset = 0;
	vec->data = malloc(size * sizeof(t_value));
	if (!vec->data)
		return (RESULT_ERROR);
	return (RESULT_OK);
}
