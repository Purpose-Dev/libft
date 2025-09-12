/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_shift.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:42:28 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/12 10:56:07 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/vectors/vector.h"

t_value	ft_vector_shift(t_vector *vec)
{
	if (!vec->length)
		return (ft_gen_val(TYPE_UNDEFINED, (t_any){0}));
	vec->length--;
	return (vec->data[vec->offset++ % vec->capacity]);
}
