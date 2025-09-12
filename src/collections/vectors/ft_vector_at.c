/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_at.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:45:38 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/12 10:49:20 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/vectors/vector.h"

t_value	ft_vector_at(const t_vector *vec, const ssize_t i)
{
	if (i >= (ssize_t)vec->length || i < -(ssize_t)vec->length)
		return (ft_gen_val(TYPE_UNDEFINED, (t_any){0}));
	if (i >= 0)
		return (vec->data[((size_t)i + vec->offset) % vec->capacity]);
	return (vec->data[(vec->length + (size_t)i + vec->offset)
			% vec->capacity]);
}
