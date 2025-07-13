/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 22:01:09 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 22:27:15 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string/ft_string.h"
#include "core/string_builder/string_builder.h"

int	sb_ensure_capacity(t_string_builder *sb, const size_t needed_capacity)
{
	char	*new_buffer;
	size_t	new_capacity;

	if (sb->capacity >= needed_capacity)
		return (1);
	new_capacity = sb->capacity * SB_GROWTH_FACTOR;
	if (new_capacity < needed_capacity)
		new_capacity = needed_capacity;
	new_buffer = malloc(new_capacity + 1);
	if (!new_buffer)
		return (0);
	ft_strlcpy(new_buffer, sb->buffer, sb->length + 1);
	free(sb->buffer);
	sb->buffer = new_buffer;
	sb->capacity = new_capacity;
	return (1);
}

int	sb_append_char(t_string_builder *sb, const char c)
{
	if (!sb || !sb_ensure_capacity(sb, sb->length))
		return (0);
	sb->buffer[sb->length] = c;
	sb->buffer[sb->length + 1] = '\0';
	sb->length++;
	return (1);
}

int	sb_append_str(t_string_builder *sb, const char *str)
{
	size_t	str_len;

	if (!sb || !str)
		return (0);
	str_len = ft_strlen(str);
	if (!sb_ensure_capacity(sb, sb->length + str_len))
		return (0);
	ft_strlcat(sb->buffer, str, sb->capacity + 1);
	sb->length += str_len;
	return (1);
}

int	sb_append_substring(t_string_builder *sb, const char *str,
							const size_t start, const size_t len)
{
	size_t	str_len;
	size_t	copy_len;

	if (!sb || !str)
		return (0);
	str_len = ft_strlen(str);
	if (start >= str_len)
		return (1);
	copy_len = len;
	if (start + copy_len > str_len)
		copy_len = str_len - start;
	if (!sb_ensure_capacity(sb, sb->length + copy_len))
		return (0);
	ft_strlcpy(sb->buffer + sb->length, str + start, copy_len + 1);
	sb->length += copy_len;
	return (1);
}
