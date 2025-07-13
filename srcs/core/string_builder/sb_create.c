/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 17:54:29 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 21:57:07 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string_builder/string_builder.h"

t_string_builder	*sb_create(void)
{
	return (sb_create_with_capacity(SB_INITIAL_CAPACITY));
}

t_string_builder	*sb_create_with_capacity(size_t capacity)
{
	t_string_builder	*sb;

	if (capacity == 0)
		capacity = SB_INITIAL_CAPACITY;
	sb = malloc(sizeof(t_string_builder));
	if (!sb)
		return (NULL);
	sb->buffer = malloc(capacity + 1);
	if (!sb->buffer)
	{
		free(sb);
		return (NULL);
	}
	sb->buffer[0] = '\0';
	sb->length = 0;
	sb->capacity = capacity;
	return (sb);
}
