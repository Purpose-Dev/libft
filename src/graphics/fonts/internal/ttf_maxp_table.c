/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttf_maxp_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 23:33:23 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 23:47:19 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/memory/ft_memory.h"
#include "graphics/fonts/ttf_internal.h"

static bool	ttf_allocate_glyphs(t_ttf_font *font)
{
	font->glyphs = malloc(sizeof(t_ttf_glyph_data) * font->maxp.num_glyphs);
	if (!font->glyphs)
		return (false);
	ft_memset(font->glyphs, 0, sizeof(t_ttf_glyph_data)
		* font->maxp.num_glyphs);
	return (true);
}

static void	ttf_parse_maxp_v1_data(t_ttf_font *font, const uint8_t *data)
{
	font->maxp.max_points = ttf_read_u16_be(data + 6);
	font->maxp.max_contours = ttf_read_u16_be(data + 8);
	font->maxp.max_composite_points = ttf_read_u16_be(data + 10);
	font->maxp.max_composite_contours = ttf_read_u16_be(data + 12);
}

bool	ttf_parse_maxp_table(t_ttf_font *font)
{
	const uint8_t	*data;

	data = ttf_get_table_data(font, TTF_TAG_MAXP);
	if (!data)
		return (false);
	font->maxp.version = ttf_read_u32_be(data);
	font->maxp.num_glyphs = ttf_read_u16_be(data + 4);
	if (font->maxp.num_glyphs == 0)
		return (false);
	if (font->maxp.version == 0x00010000)
		ttf_parse_maxp_v1_data(font, data);
	return (ttf_allocate_glyphs(font));
}
