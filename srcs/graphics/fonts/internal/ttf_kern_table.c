/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttf_kern_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 23:33:50 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 23:55:54 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "core/memory/ft_memory.h"
#include "graphics/fonts/ttf_internal.h"

static bool	ttf_parse_kern_subtable_format0(t_ttf_font *font,
		const uint8_t *subtable_data)
{
	uint16_t	n_pairs;
	uint32_t	i;

	n_pairs = ttf_read_u16_be(subtable_data + 6);
	if (n_pairs == 0)
		return (true);
	font->kern_pairs = malloc(sizeof(t_ttf_kern_pair) * n_pairs);
	if (!font->kern_pairs)
		return (false);
	i = 0;
	while (i < n_pairs)
	{
		font->kern_pairs[i].left_glyph = ttf_read_u16_be(
				subtable_data + 14 + i * 6);
		font->kern_pairs[i].right_glyph = ttf_read_u16_be(
				subtable_data + 14 + i * 6 + 2);
		font->kern_pairs[i].value = ttf_read_i16_be(
				subtable_data + 14 + i * 6 + 4);
		i++;
	}
	font->kern_count = n_pairs;
	return (true);
}

static bool	ttf_parse_kern_subtable(t_ttf_font *font, const uint8_t *data,
		uint32_t subtable_offset)
{
	const uint8_t	*subtable_data;
	uint16_t		coverage;
	uint8_t			format;

	subtable_data = data + subtable_offset;
	coverage = ttf_read_u16_be(subtable_data + 4);
	format = (uint8_t)(coverage >> 8) & 0xFF;
	if (format == 0 && (coverage & 0x01))
		return (ttf_parse_kern_subtable_format0(font, subtable_data));
	return (true);
}

bool	ttf_parse_kern_table(t_ttf_font *font)
{
	const uint8_t	*data;
	uint16_t		n_tables;

	data = ttf_get_table_data(font, TTF_TAG_KERN);
	if (!data)
		return (true);
	n_tables = ttf_read_u16_be(data + 2);
	if (n_tables == 0)
		return (true);
	return (ttf_parse_kern_subtable(font, data, 4));
}
