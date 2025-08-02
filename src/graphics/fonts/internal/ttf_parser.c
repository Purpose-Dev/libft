/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttf_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:27:26 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 23:27:53 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "graphics/fonts/ttf_internal.h"

static bool	ttf_parse_font_header(t_ttf_font *font)
{
	const uint8_t	*data;
	uint32_t		scalar_type;

	if (font->data_size < 12)
		return (false);
	data = font->data;
	scalar_type = ttf_read_u32_be(data);
	if (scalar_type != 0x00010000 && scalar_type != 0x74727565)
		return (false);
	font->num_tables = ttf_read_u16_be(data + 4);
	return (font->num_tables > 0);
}

static bool	ttf_parse_table_directory(t_ttf_font *font)
{
	const uint8_t	*data;
	uint32_t		offset;
	uint16_t		i;

	if ((long)font->data_size < 12 + font->num_tables * 16)
		return (false);
	font->tables = malloc(sizeof(t_ttf_table_record) * font->num_tables);
	if (!font->tables)
		return (false);
	data = font->data + 12;
	offset = 0;
	i = 0;
	while (i < font->num_tables)
	{
		font->tables[i].tag = ttf_read_u32_be(data + offset);
		font->tables[i].checksum = ttf_read_u32_be(data + offset + 4);
		font->tables[i].offset = ttf_read_u32_be(data + offset + 8);
		font->tables[i].length = ttf_read_u32_be(data + offset + 12);
		offset += 16;
		i++;
	}
	return (true);
}

static bool	ttf_parse_required_tables(t_ttf_font *font)
{
	if (!ttf_parse_head_table(font))
		return (false);
	if (!ttf_parse_hhea_table(font))
		return (false);
	if (!ttf_parse_maxp_table(font))
		return (false);
	return (true);
}

static void	ttf_parse_optional_tables(t_ttf_font *font)
{
	ttf_parse_cmap_table(font);
	ttf_parse_kern_table(font);
	ttf_parse_name_table(font);
}

bool	ttf_parse_font_data(t_ttf_font *font)
{
	if (!font || !font->data)
		return (false);
	if (!ttf_parse_font_header(font))
		return (false);
	if (!ttf_parse_table_directory(font))
		return (false);
	if (!ttf_parse_required_tables(font))
		return (false);
	ttf_parse_optional_tables(font);
	return (true);
}
