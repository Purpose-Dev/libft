/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 22:01:42 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 22:35:54 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/ctype/ft_ctype.h"
#include "core/memory/ft_memory.h"
#include "core/string/ft_string.h"
#include "core/string_builder/string_builder.h"

char	*sb_to_string(t_string_builder *sb)
{
	char	*result;

	if (!sb)
		return (NULL);
	result = ft_strdup(sb->buffer);
	return (result);
}

size_t	sb_length(t_string_builder *sb)
{
	if (!sb)
		return (0);
	return (sb->length);
}

size_t	sb_capacity(t_string_builder *sb)
{
	if (!sb)
		return (0);
	return (sb->capacity);
}

int	sb_is_empty(t_string_builder *sb)
{
	if (!sb)
		return (1);
	return (sb->length == 0);
}

void	sb_trim(t_string_builder *sb)
{
	size_t	start;
	size_t	end;

	if (!sb || sb->length == 0)
		return ;
	start = 0;
	while (start < sb->length && ft_isspace(sb->buffer[start]))
		start++;
	end = sb->length - 1;
	while (end > start && ft_isspace(sb->buffer[end]))
		end--;
	if (start > 0)
		ft_memmove(sb->buffer, sb->buffer + start, end - start + 1);
	sb->length = end - start + 1;
	sb->buffer[sb->length] = '\0';
}
