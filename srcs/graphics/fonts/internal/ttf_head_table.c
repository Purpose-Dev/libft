/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttf_head_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 17:28:16 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 23:22:15 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/fonts/ttf_internal.h"

static bool	ttf_parse_head_basic_info(t_ttf_font *font, const uint8_t *data)
{
	font->head.version = ttf_read_u32_be(data);
	font->head.font_revision = ttf_read_u32_be(data + 4);
	font->head.checksum_adjustment = ttf_read_u32_be(data + 8);
	font->head.magic_number = ttf_read_u32_be(data + 12);
	if (font->head.magic_number != 0x5F0F3CF5)
		return (false);
	return (true);
}

static void	ttf_parse_head_metrics(t_ttf_font *font, const uint8_t *data)
{
	font->head.flags = ttf_read_u16_be(data + 16);
	font->head.units_per_em = ttf_read_u16_be(data + 18);
	font->head.created = (int64_t)ttf_read_u64_be(data + 20);
	font->head.modified = (int64_t)ttf_read_u64_be(data + 28);
	font->head.x_min = ttf_read_i16_be(data + 36);
	font->head.x_max = ttf_read_i16_be(data + 38);
	font->head.y_min = ttf_read_i16_be(data + 40);
	font->head.y_max = ttf_read_i16_be(data + 42);
}

static void	ttf_parse_head_style_info(t_ttf_font *font, const uint8_t *data)
{
	font->head.mac_style = ttf_read_u16_be(data + 44);
	font->head.lowest_rec_ppem = ttf_read_u16_be(data + 46);
	font->head.font_direction_hint = ttf_read_i16_be(data + 48);
	font->head.index_to_loc_format = ttf_read_i16_be(data + 50);
	font->head.glyph_data_format = ttf_read_i16_be(data + 52);
}

bool	ttf_parse_head_table(t_ttf_font *font)
{
	const uint8_t	*data;

	data = ttf_get_table_data(font, TTF_TAG_HEAD);
	if (!data)
		return (false);
	if (!ttf_parse_head_basic_info(font, data))
		return (false);
	ttf_parse_head_metrics(font, data);
	ttf_parse_head_style_info(font, data);
	return (true);
}
