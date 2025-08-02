/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttf_cmap_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 23:33:39 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 23:56:48 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/memory/ft_memory.h"
#include "graphics/fonts/ttf_internal.h"

static uint32_t	ttf_find_unicode_subtable_offset(const uint8_t *data,
		const uint16_t num_tables)
{
	uint16_t	i;
	uint16_t	platform_id;
	uint16_t	encoding_id;

	i = 0;
	while (i < num_tables)
	{
		platform_id = ttf_read_u16_be(data + 4 + i * 8);
		encoding_id = ttf_read_u16_be(data + 4 + i * 8 + 2);
		if ((platform_id == 0) || (platform_id == 3 && encoding_id == 1))
			return (ttf_read_u32_be(data + 4 + i * 8 + 4));
		i++;
	}
	return (0);
}

static bool	ttf_parse_cmap_format4(t_ttf_font *font)
{
	font->cmap_entries = malloc(sizeof(t_ttf_cmap_entry) * 256);
	if (!font->cmap_entries)
		return (false);
	font->cmap_entry_count = 256;
	ft_memset(font->cmap_entries, 0, sizeof(t_ttf_cmap_entry) * 256);
	return (true);
}

static bool	ttf_parse_cmap_subtable(t_ttf_font *font, const uint8_t *data,
		const uint32_t offset)
{
	const uint8_t	*subtable;
	uint16_t		format;

	subtable = data + offset;
	format = ttf_read_u16_be(subtable);
	if (format == 4)
		return (ttf_parse_cmap_format4(font));
	return (false);
}

bool	ttf_parse_cmap_table(t_ttf_font *font)
{
	const uint8_t	*data;
	uint16_t		num_tables;
	uint32_t		subtable_offset;

	data = ttf_get_table_data(font, TTF_TAG_CMAP);
	if (!data)
		return (false);
	num_tables = ttf_read_u16_be(data + 2);
	subtable_offset = ttf_find_unicode_subtable_offset(data, num_tables);
	if (subtable_offset == 0)
		return (false);
	return (ttf_parse_cmap_subtable(font, data, subtable_offset));
}
