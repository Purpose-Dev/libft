/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_advanced.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 22:01:59 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 22:38:07 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/string_builder/string_builder.h"

int	sb_delete_char(t_string_builder *sb, const size_t index)
{
	size_t	i;

	if (!sb || index >= sb->length)
		return (0);
	i = index;
	while (i < sb->length + 1)
	{
		sb->buffer[i] = sb->buffer[i + 1];
		i++;
	}
	sb->length--;
	sb->buffer[sb->length] = '\0';
	return (1);
}

int	sb_delete_range(t_string_builder *sb, const size_t start, const size_t end)
{
	size_t	range_len;
	size_t	i;

	if (!sb || start >= sb->length || end <= start || end > sb->length)
		return (0);
	range_len = end - start;
	i = start;
	while (i + range_len < sb->length)
	{
		sb->buffer[i] = sb->buffer[i + range_len];
		i++;
	}
	sb->length -= range_len;
	sb->buffer[sb->length] = '\0';
	return (1);
}

int	sb_reverse(t_string_builder *sb)
{
	size_t	i;
	size_t	j;
	char	temp;

	if (!sb || sb->length <= 1)
		return (0);
	i = 0;
	j = sb->length - 1;
	while (i < j)
	{
		temp = sb->buffer[i];
		sb->buffer[i] = sb->buffer[j];
		sb->buffer[j] = temp;
		i++;
		j--;
	}
	return (1);
}

int	sb_replace_char(t_string_builder *sb, const char old_char,
					const char new_char)
{
	size_t	i;

	if (!sb)
		return (0);
	i = 0;
	while (i < sb->length)
	{
		if (sb->buffer[i] == old_char)
			sb->buffer[i] = new_char;
		i++;
	}
	return (1);
}
