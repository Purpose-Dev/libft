/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_foreach.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:38:56 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/12 10:51:12 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/vectors/vector.h"

void	ft_vector_foreach(const t_vector *vec, void (*fn)(size_t, t_value))
{
	size_t	i;

	i = 0;
	while (i < vec->length)
	{
		fn(i, vec->data[(vec->offset + i) % vec->capacity]);
		i++;
	}
}
