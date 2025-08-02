/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 22:02:14 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 22:41:50 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/memory/ft_memory.h"
#include "core/string/ft_string.h"
#include "core/string_builder/string_builder.h"

static int	sb_expand_buffer(t_string_builder *sb, const size_t pos,
							const size_t old_len, const size_t new_len)
{
	size_t	i;

	if (!sb_ensure_capacity(sb, sb->length + new_len - old_len))
		return (0);
	i = sb->length;
	while (i > pos + old_len - 1)
	{
		sb->buffer[i + new_len - old_len - 1] = sb->buffer[i - 1];
		i--;
	}
	sb->length += new_len - old_len;
	return (1);
}

static void	sb_shrink_buffer(t_string_builder *sb, const size_t pos,
					const size_t old_len, const size_t new_len)
{
	size_t	i;

	i = pos + new_len;
	while (i < sb->length - old_len + new_len)
	{
		sb->buffer[i] = sb->buffer[i + old_len - new_len];
		i++;
	}
	sb->length -= old_len - new_len;
}

static int	sb_replace_single(t_string_builder *sb, const size_t pos,
						const char *old_str, const char *new_str)
{
	size_t	old_len;
	size_t	new_len;

	old_len = ft_strlen(old_str);
	new_len = ft_strlen(new_str);
	if (new_len > old_len)
	{
		if (!sb_expand_buffer(sb, pos, old_len, new_len))
			return (0);
	}
	else if (new_len < old_len)
		sb_shrink_buffer(sb, pos, old_len, new_len);
	ft_memcpy(sb->buffer + pos, new_str, new_len);
	sb->buffer[sb->length] = '\0';
	return (1);
}

int	sb_replace(t_string_builder *sb, const char *old_str, const char *new_str)
{
	char	*pos;
	size_t	offset;

	if (!sb || !old_str || !new_str)
		return (0);
	offset = 0;
	while (offset < sb->length)
	{
		pos = ft_strstr(sb->buffer + offset, old_str);
		if (!pos)
			break ;
		offset = (size_t)(pos - sb->buffer);
		if (!sb_replace_single(sb, offset, old_str, new_str))
			return (0);
		offset += ft_strlen(new_str);
	}
	return (1);
}
