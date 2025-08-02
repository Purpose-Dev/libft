/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 22:01:31 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/13 22:27:06 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/memory/ft_memory.h"
#include "core/string/ft_string.h"
#include "core/string_builder/string_builder.h"
#include "io/ft_printf.h"

int	sb_append_int(t_string_builder *sb, const int num)
{
	char	*str;
	int		result;

	if (!sb)
		return (0);
	str = ft_itoa(num);
	if (!str)
		return (0);
	result = sb_append_str(sb, str);
	free(str);
	return (result);
}

int	sb_append_format(t_string_builder *sb, const char *format, ...)
{
	va_list	args;
	char	*temp_buffer;
	int		needed_size;
	size_t	buffer_size;
	int		result;

	if (!sb || !format)
		return (0);
	va_start(args, format);
	needed_size = ft_vsnprintf(NULL, 0, format, args);
	va_end(args);
	if (needed_size <= 0)
		return (0);
	buffer_size = (size_t)needed_size + 1;
	temp_buffer = malloc(buffer_size);
	if (!temp_buffer)
		return (0);
	va_start(args, format);
	ft_vsnprintf(temp_buffer, buffer_size, format, args);
	va_end(args);
	result = sb_append_str(sb, temp_buffer);
	free(temp_buffer);
	return (result);
}

int	sb_insert_char(t_string_builder *sb, const size_t index, const char c)
{
	size_t	i;

	if (!sb || index > sb->length)
		return (0);
	if (!sb_append_char(sb, c))
		return (0);
	i = sb->length - 1;
	while (i > index)
	{
		sb->buffer[i] = sb->buffer[i - 1];
		i--;
	}
	sb->buffer[index] = c;
	return (1);
}

int	sb_insert_str(t_string_builder *sb, size_t index, const char *str)
{
	size_t	str_len;
	size_t	i;

	if (!sb || !str || index > sb->length)
		return (0);
	str_len = ft_strlen(str);
	if (str_len == 0)
		return (1);
	if (!sb_ensure_capacity(sb, sb->length + str_len))
		return (0);
	i = sb->length;
	while (i > index)
	{
		sb->buffer[i + str_len - 1] = sb->buffer[i - 1];
		i--;
	}
	ft_memcpy(sb->buffer + index, str, str_len);
	sb->length += str_len;
	sb->buffer[sb->length] = '\0';
	return (1);
}
