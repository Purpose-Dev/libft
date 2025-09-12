/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:40:02 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/12 10:53:20 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "collections/vectors/vector.h"

void	ft_vector_map(const t_vector *vec, t_value (*fn)(size_t, t_value))
{
	size_t	i;
	t_value	*cell;

	i = 0;
	while (i < vec->length)
	{
		cell = vec->data + (vec->offset + i) % vec->capacity;
		*cell = fn(i, *cell);
		i++;
	}
}
