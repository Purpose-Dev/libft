/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_every.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:40:19 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/09/12 10:50:29 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

#include "collections/vectors/vector.h"

_Bool	ft_vector_every(const t_vector *vec, _Bool (*fn)(size_t, t_value))
{
	size_t	i;

	i = 0;
	while (i < vec->length)
	{
		if (!fn(i, vec->data[(vec->offset + i) % vec->capacity]))
			return (false);
		i++;
	}
	return (true);
}
