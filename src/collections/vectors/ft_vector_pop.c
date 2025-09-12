/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_pop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:42:15 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/12 10:54:30 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/vectors/vector.h"

t_value	ft_vector_pop(t_vector *vec)
{
	if (!vec->length)
		return (ft_gen_val(TYPE_UNDEFINED, (t_any){0}));
	return (vec->data[(vec->offset + vec->length-- - 1) % vec->capacity]);
}
