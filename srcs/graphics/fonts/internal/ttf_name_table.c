/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttf_name_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 09:49:05 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/21 10:05:13 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/fonts/ttf_internal.h"

static void	ttf_copy_name_string(char *dest, const uint8_t *src,
	const uint16_t length)
{
	uint16_t	i;
	uint16_t	dest_pos;

	i = 0;
	dest_pos = 0;
	while (i < length && dest_pos < TTF_NAME_BUFFER_SIZE - 1)
	{
		if (src[i] != 0)
			dest[dest_pos++] = (char)src[i];
		i++;
	}
	dest[dest_pos] = '\0';
}

static void	ttf_extract_name_record(t_ttf_font *font, const uint8_t *data,
	const uint16_t name_id, const uint16_t length)
{
	const uint8_t	*name_data;

	name_data = data + 0;
	if (name_id == 1 && font->family_name[0] == '\0')
		ttf_copy_name_string(font->family_name, (const uint8_t *)name_data,
			length);
	else if (name_id == 2 && font->style_name[0] == '\0')
		ttf_copy_name_string(font->style_name, (const uint8_t *)name_data,
			length);
}

static void	ttf_process_name_record(t_ttf_font *font, const uint8_t *data,
	const uint8_t *name_record, const uint16_t string_offset)
{
	uint16_t	name_id;
	uint16_t	length;
	uint16_t	offset;

	name_id = ttf_read_u16_be(name_record + 6);
	length = ttf_read_u16_be(name_record + 8);
	offset = ttf_read_u16_be(name_record + 10);
	if (name_id == 1 || name_id == 2)
		ttf_extract_name_record(font, data + string_offset + offset,
			name_id, length);
}

bool	ttf_parse_name_table(t_ttf_font *font)
{
	const uint8_t	*data;
	uint16_t		count;
	uint16_t		string_offset;
	uint16_t		i;

	data = ttf_get_table_data(font, TTF_TAG_NAME);
	if (!data)
		return (false);
	count = ttf_read_u16_be(data + 2);
	string_offset = ttf_read_u16_be(data + 4);
	font->family_name[0] = '\0';
	font->style_name[0] = '\0';
	i = 0;
	while (i < count)
	{
		ttf_process_name_record(font, data, data + 6 + i * 12, string_offset);
		i++;
	}
	return (true);
}
