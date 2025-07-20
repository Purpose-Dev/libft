/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ttf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-qoqu <rel-qoqu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 12:40:43 by rel-qoqu          #+#    #+#             */
/*   Updated: 2025/07/20 17:06:31 by rel-qoqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TTF_H
# define TTF_H

# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include "../color.h"

typedef enum e_ttf_hinting_mode
{
	TTF_HINTING_NONE = 0,
	TTF_HINTING_LIGHT = 1,
	TTF_HINTING_FULL = 2
}	t_ttf_hinting_mode;

typedef enum e_ttf_pixel_format
{
	TTF_FORMAT_GRAYSCALE = 1,
	TTF_FORMAT_RGB = 3,
	TTF_FORMAT_RGBA = 4
}	t_ttf_pixel_format;

typedef struct s_ttf_font			t_ttf_font;
typedef struct s_ttf_bitmap			t_ttf_bitmap;
typedef struct s_ttf_render_context	t_ttf_render_context;

typedef struct s_ttf_text_metrics
{
	float		width;
	float		height;
	float		ascent;
	float		descent;
	float		line_gap;
	uint32_t	glyph_count;
}	t_ttf_text_metrics;

typedef struct s_ttf_glyph_metrics
{
	float		advance_width;
	float		left_side_bearing;
	float		width;
	float		height;
	float		bearing_x;
	float		bearing_y;
}	t_ttf_glyph_metrics;

typedef struct s_ttf_font_info
{
	char		*family_name;
	char		*style_name;
	uint16_t	units_per_em;
	int16_t		ascender;
	int16_t		descender;
	int16_t		line_gap;
	uint16_t	num_glyphs;
	bool		has_kerning;
}	t_ttf_font_info;

t_ttf_font				*ttf_load_font(const char *filename);
void					ttf_free_font(t_ttf_font *font);
t_ttf_font_info			*ttf_get_font_info(t_ttf_font *font);
void					ttf_free_font_info(t_ttf_font_info *info);

t_ttf_bitmap			*ttf_create_bitmap(uint32_t width, uint32_t height,
							t_ttf_pixel_format format);
void					ttf_free_bitmap(t_ttf_bitmap *bitmap);
void					ttf_clear_bitmap(t_ttf_bitmap *bitmap, uint32_t color);
uint8_t					*ttf_get_bitmap_data(t_ttf_bitmap *bitmap);
void					ttf_get_bitmap_info(t_ttf_bitmap *bitmap,
							uint32_t *width, uint32_t *height,
							uint32_t *stride);

t_ttf_render_context	*ttf_create_render_context(t_ttf_bitmap *target,
							float scale_x, float scale_y);
void					ttf_free_render_context(t_ttf_render_context *ctx);
void					ttf_set_position(t_ttf_render_context *ctx, float x,
							float y);
void					ttf_set_color(t_ttf_render_context *ctx,
							t_rgba_color color);
void					ttf_set_hinting(t_ttf_render_context *ctx,
							t_ttf_hinting_mode mode);

bool					ttf_render_text(t_ttf_font *font, const char *text,
							t_ttf_render_context *ctx);
bool					ttf_render_glyph(t_ttf_font *font, uint32_t unicode,
							t_ttf_render_context *ctx);
bool					ttf_render_glyph(t_ttf_font *font, uint32_t unicode,
							t_ttf_render_context *ctx);

t_ttf_text_metrics		ttf_measure_text(t_ttf_font *font, const char *text,
							float scale);
float					ttf_get_text_width(t_ttf_font *font, const char *text,
							float scale);
float					ttf_get_line_height(t_ttf_font *font, float scale);
t_ttf_glyph_metrics		ttf_get_glyph_metrics(t_ttf_font *font,
							uint32_t unicode, float scale);

float					ttf_get_kerning(t_ttf_font *font, uint32_t left,
							uint32_t right, float scale);
uint32_t				ttf_utf8_to_unicode(const char *utf8_str,
							size_t *bytes_consumed);
bool					ttf_has_glyph(t_ttf_font *font, uint32_t unicode);

bool					ttf_validate_font(t_ttf_font *font);
bool					ttf_is_font_loaded(t_ttf_font *font);

#endif // TTF_H
