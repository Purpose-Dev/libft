/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttf_internal.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 13:29:46 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 17:07:26 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TTF_INTERNAL_H
# define TTF_INTERNAL_H

# include <stdbool.h>
# include <stdint.h>
# include "ttf.h"

# define TTF_MAX_CONTOURS 64
# define TTF_MAX_POINTS 2048
# define TTF_MAX_COMPOSITES 32
# define TTF_KERN_PAIRS_MAX 8192
# define TTF_CMAP_ENTRIES_MAX 16384
# define TTF_GLYPH_CACHE_SIZE 512
# define TTF_NAME_BUFFER_SIZE 256

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
	float		x;
	float		y;
	uint8_t		flags;
	bool		on_curve;
}	t_ttf_point;

typedef struct s_ttf_contour
{
	t_ttf_point	*points;
	uint16_t	point_count;
	uint16_t	end_point_index;
}	t_ttf_contour;

typedef struct s_ttf_composite_component
{
	float		transform[6];
	uint16_t	glyph_index;
	uint16_t	flags;
	int16_t		arg1;
	int16_t		arg2;
}	t_ttf_composite_component;

typedef struct s_ttf_glyph_data
{
	t_ttf_contour				*contours;
	t_ttf_composite_component	*components;
	uint8_t						*instructions;
	int16_t						number_of_contours;
	int16_t						x_min;
	int16_t						y_min;
	int16_t						x_max;
	int16_t						y_max;
	uint16_t					advance_width;
	int16_t						left_side_bearing;
	uint16_t					component_count;
	uint16_t					instruction_length;
	bool						is_loaded;
}	t_ttf_glyph_data;

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

typedef struct s_ttf_table_record
{
	uint32_t	tag;
	uint32_t	checksum;
	uint32_t	offset;
	uint32_t	length;
}	t_ttf_table_record;

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
}	t_ttf_maxp_table;

struct s_ttf_font
{
	uint8_t				*data;
	size_t				data_size;
	uint16_t			num_tables;
	t_ttf_table_record	*tables;
	t_ttf_head_table	head;
	t_ttf_hhea_table	hhea;
	t_ttf_maxp_table	maxp;
	t_ttf_glyph_data	*glyphs;
	uint32_t			*glyph_offsets;
	t_ttf_kern_pair		*kern_pairs;
	uint32_t			kern_count;
	t_ttf_cmap_entry	*cmap_entries;
	uint32_t			cmap_entry_count;
	uint16_t			*h_metrics;
	char				family_name[TTF_NAME_BUFFER_SIZE];
	char				style_name[TTF_NAME_BUFFER_SIZE];
	bool				is_loaded;
};

struct s_ttf_bitmap
{
	uint8_t				*pixels;
	uint32_t			width;
	uint32_t			height;
	uint32_t			stride;
	t_ttf_pixel_format	format;
};

struct s_ttf_render_context
{
	t_ttf_bitmap		*target;
	float				scale_x;
	float				scale_y;
	float				pos_x;
	float				pos_y;
	uint8_t				color[4];
	t_ttf_hinting_mode	hinting_mode;
	bool				subpixel_rendering;
	bool				gamma_correction;
};

uint16_t			ttf_read_u16_be(const uint8_t *data);
uint32_t			ttf_read_u32_be(const uint8_t *data);
int16_t				ttf_read_i16_be(const uint8_t *data);
int32_t				ttf_read_i32_be(const uint8_t *data);
uint64_t			ttf_read_u64_be(const uint8_t *data);

bool				ttf_parse_font_data(t_ttf_font *font);
bool				ttf_parse_head_table(t_ttf_font *font);
bool				ttf_parse_hhea_table(t_ttf_font *font);
bool				ttf_parse_maxp_table(t_ttf_font *font);
bool				ttf_parse_cmap_table(t_ttf_font *font);
bool				ttf_parse_kern_table(t_ttf_font *font);
bool				ttf_parse_name_table(t_ttf_font *font);

t_ttf_table_record	*ttf_find_table(t_ttf_font *font, uint32_t tag);
bool				ttf_validate_table_access(t_ttf_font *font,
						uint32_t offset, uint32_t length);
uint8_t				*ttf_get_table_data(t_ttf_font *font, uint32_t tag);

bool				ttf_load_glyph_data(t_ttf_font *font,
						uint16_t glyph_index);
uint16_t			ttf_get_glyph_index_internal(t_ttf_font *font,
						uint32_t unicode);
int16_t				ttf_get_kerning_value_internal(t_ttf_font *font,
						uint16_t left_glyph, uint16_t right_glyph);

#endif // TTF_INTERNAL_H
