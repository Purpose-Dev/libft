/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttf_hhea_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 23:32:59 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 23:40:15 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/fonts/ttf_internal.h"

static void	ttf_parse_hhea_metrics(t_ttf_font *font, const uint8_t *data)
{
	font->hhea.version = ttf_read_u32_be(data);
	font->hhea.ascender = ttf_read_i16_be(data + 4);
	font->hhea.descender = ttf_read_i16_be(data + 6);
	font->hhea.line_gap = ttf_read_i16_be(data + 8);
	font->hhea.advance_width_max = ttf_read_u16_be(data + 10);
}

static void	ttf_parse_hhea_bearings(t_ttf_font *font, const uint8_t *data)
{
	font->hhea.min_left_side_bearing = ttf_read_i16_be(data + 12);
	font->hhea.min_right_side_bearing = ttf_read_i16_be(data + 14);
	font->hhea.x_max_extent = ttf_read_i16_be(data + 16);
}

static void	ttf_parse_hhea_caret_info(t_ttf_font *font, const uint8_t *data)
{
	font->hhea.caret_slope_rise = ttf_read_i16_be(data + 18);
	font->hhea.caret_slope_run = ttf_read_i16_be(data + 20);
	font->hhea.caret_offset = ttf_read_i16_be(data + 22);
	font->hhea.num_h_metrics = ttf_read_u16_be(data + 24);
}

bool	ttf_parse_hhea_table(t_ttf_font *font)
{
	const uint8_t	*data;

	data = ttf_get_table_data(font, TTF_TAG_HHEA);
	if (!data)
		return (false);
	ttf_parse_hhea_metrics(font, data);
	ttf_parse_hhea_bearings(font, data);
	ttf_parse_hhea_caret_info(font, data);
	return (true);
}
