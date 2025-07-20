/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ttf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 12:40:43 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 13:23:14 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TTF_H
# define FT_TTF_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>

# define TTF_MAX_CONTOURS 64
# define TTF_MAX_POINTS 1024
# define TTF_MAX_COMPOSITES 16
# define TTF_KERN_PAIRS_MAX 4096
# define TTF_CMAP_ENTRIES_MAX 8192
# define TTF_GLYPH_CACHE_SIZE 256
# define TTF_HINTING_NONE 0
# define TTF_HINTING_LIGHT 1
# define TTF_HINTING_FULL 2

# define TTF_TAG_CMAP 0x636D6170
# define TTF_TAG_GLYF 0x676C7966
# define TTF_TAG_HEAD 0x68656164
# define TTF_TAG_HHEA 0x68686561
# define TTF_TAG_HMTX 0x686D7478
# define TTF_TAG_KERN 0x6B65726E
# define TTF_TAG_LOCA 0x6C6F6361
# define TTF_TAG_MAXP 0x6D617870
# define TTF_TAG_NAME 0x6E616D65
# define TTF_TAG_OS2  0x4F532F32
# define TTF_TAG_POST 0x706F7374

# define TTF_GLYPH_ON_CURVE 0x01
# define TTF_GLYPH_X_SHORT 0x02
# define TTF_GLYPH_Y_SHORT 0x04
# define TTF_GLYPH_REPEAT 0x08
# define TTF_GLYPH_X_SAME 0x10
# define TTF_GLYPH_Y_SAME 0x20
# define TTF_GLYPH_OVERLAP 0x40

typedef struct s_ttf_point
{
	float	x;
	float	y;
	uint8_t	flags;
	bool	on_curve;
}	t_ttf_point;

typedef struct s_ttf_contour
{
	t_ttf_point	*points;
	uint16_t	point_count;
	uint16_t	end_point_index;
}	t_ttf_contour;

typedef struct s_ttf_composite_glyph {
	float		transform[6];
	int16_t		arg1;
	int16_t		arg2;
	uint16_t	glyph_index;
	uint16_t	flags;
}	t_ttf_composite_glyph;

typedef struct s_ttf_glyph_metrics {
	uint16_t	advance_width;
	int16_t		left_side_bearing;
	int16_t		x_min;
	int16_t		x_max;
	int16_t		y_min;
	int16_t		y_max;
}	t_ttf_glyph_metrics;

typedef struct s_ttf_glyph
{
	t_ttf_glyph_metrics		metrics;
	t_ttf_contour			*contours;
	t_ttf_composite_glyph	*composites;
	int16_t					number_of_contours;
	uint8_t					*instructions;
	uint16_t				composite_count;
	uint16_t				glyph_offset;
	uint16_t				instruction_length;
	bool					is_loaded;
}	t_ttf_glyph;

typedef struct s_ttf_kern_pair
{
	uint16_t	left_glyph;
	uint16_t	right_glyph;
	int16_t		value;
}	t_ttf_kern_pair;

typedef struct s_ttf_cmap_entry
{
	uint32_t	unicode_value;
	uint16_t	glyph_index;
}	t_ttf_cmap_entry;

typedef struct s_ttf_cmap_subtable
{
	uint16_t	platform_id;
	uint16_t	encoding_id;
	uint32_t	offset;
	uint16_t	format;
	uint32_t	length;
	uint16_t	language;
}	t_ttf_cmap_subtable;

typedef struct s_ttf_table_directory
{
	uint32_t	tag;
	uint32_t	checksum;
	uint32_t	offset;
	uint32_t	length;
}	t_ttf_table_directory;

typedef struct s_ttf_font_header
{
	uint32_t	version;
	uint16_t	num_tables;
	uint16_t	search_range;
	uint16_t	entry_selector;
	uint16_t	range_shift;
}	t_ttf_font_header;

typedef struct s_ttf_head_table
{
	uint32_t	version;
	uint32_t	font_revision;
	uint32_t	checksum_adjustment;
	uint32_t	magic_number;
	uint16_t	flags;
	uint16_t	units_per_em;
	int64_t		created;
	int64_t		modified;
	int16_t		x_min;
	int16_t		y_min;
	int16_t		x_max;
	int16_t		y_max;
	uint16_t	mac_style;
	uint16_t	lowest_rec_ppem;
	int16_t		font_direction_hint;
	int16_t		index_to_loc_format;
	int16_t		glyph_data_format;
}	t_ttf_head_table;

typedef struct s_ttf_hhea_table
{
	uint32_t	version;
	int16_t		ascender;
	int16_t		descender;
	int16_t		line_gap;
	uint16_t	advance_width_max;
	int16_t		min_left_side_bearing;
	int16_t		min_right_side_bearing;
	int16_t		x_max_extent;
	int16_t		caret_slope_rise;
	int16_t		caret_slope_run;
	int16_t		caret_offset;
	uint16_t	num_h_metrics;
}	t_ttf_hhea_table;

typedef struct s_ttf_maxp_table
{
	uint32_t	version;
	uint16_t	num_glyphs;
	uint16_t	max_points;
	uint16_t	max_contours;
	uint16_t	max_composite_points;
	uint16_t	max_composite_contours;
	uint16_t	max_zones;
	uint16_t	max_twilight_points;
	uint16_t	max_storage;
	uint16_t	max_function_defs;
	uint16_t	max_instruction_defs;
	uint16_t	max_stack_elements;
	uint16_t	max_size_of_instructions;
	uint16_t	max_component_elements;
	uint16_t	max_component_depth;
}	t_ttf_maxp_table;

typedef struct s_ttf_font
{
	t_ttf_table_directory	*tables;
	uint8_t					*data;
	t_ttf_glyph				*glyphs;
	uint32_t				*glyph_offsets;
	t_ttf_kern_pair			*kern_pairs;
	t_ttf_cmap_subtable		*cmap_subtables;
	t_ttf_cmap_entry		*cmap_entries;
	uint16_t				*h_metrics;
	size_t					data_size;
	t_ttf_font_header		header;
	t_ttf_head_table		head;
	t_ttf_hhea_table		hhea;
	t_ttf_maxp_table		maxp;
	uint32_t				kern_count;
	uint32_t				cmap_subtable_count;
	uint32_t				cmap_entry_count;
	bool					is_loaded;
}	t_ttf_font;

typedef struct s_ttf_bitmap
{
	uint8_t		*pixels;
	uint32_t	width;
	uint32_t	height;
	uint32_t	stride;
	uint8_t		bytes_per_pixel;
}	t_ttf_bitmap;

typedef struct s_ttf_render_context
{
	t_ttf_bitmap	*target;
	uint8_t			color[4];
	float			scale_x;
	float			scale_y;
	float			pos_x;
	float			pos_y;
	uint8_t			hinting_mode;
	bool			subpixel_rendering;
	bool			gamma_correction;
}	t_ttf_render_context;

typedef struct s_ttf_text_metrics
{
	float		width;
	float		height;
	float		ascent;
	float		descent;
	float		line_gap;
	uint32_t	glyph_count;
}	t_ttf_text_metrics;

typedef struct s_ttf_glyph_cache_entry
{
	t_ttf_bitmap	*bitmap;
	uint16_t		glyph_index;
	float			scale;
	bool			is_valid;
}	t_ttf_glyph_cache_entry;

#endif // FT_TTF_H
