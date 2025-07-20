/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rect.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 16:03:38 by smamalig          #+#    #+#             */
/*   Updated: 2025/07/20 13:33:50 by smamalig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "graphics/ft_ui.h"
#include <math.h>
#include <stdint.h>

static inline float	dist_to_edge(int32_t x, int32_t y)
{
	return (sqrtf((float)(x * x + y * y)));
}

static inline float	aa_coverage(int32_t x, int32_t y, int32_t r)
{
	const float	d = dist_to_edge(x, y);

	if (d <= (float)r - 1.0f)
		return (1.0f);
	if (d >= (float)r + 1.0f)
		return (0.0f);
	return (1.0f - (d - ((float)r - 1.0f)));
}

static inline uint32_t	blend_u32(uint32_t fg, uint32_t bg, float alpha)
{
	uint32_t	inv_a;
	uint32_t	a;
	uint32_t	r;
	uint32_t	g;
	uint32_t	b;

	inv_a = (uint32_t)(alpha * 0xffp0f);
	if (inv_a == 0)
		return (bg);
	if (inv_a == 255)
		return (fg);
	a = 256 - inv_a;
	r = (((fg >> 16) & 0xff) * a + ((bg >> 16) & 0xff) * inv_a) >> 8;
	g = (((fg >> 8) & 0xff) * a + ((bg >> 8) & 0xff) * inv_a) >> 8;
	b = ((fg & 0xff) * a + (bg & 0xff) * inv_a) >> 8;
	return ((r << 16) | (g << 8) | b);
}

static inline void	ui_rect_xloop(t_ui_context *ui, t_ui_base *rect,
	int32_t dy, int32_t r)
{
	int32_t		dx;
	uint32_t	fill;
	float		alpha;

	dx = -1;
	while (++dx < rect->w)
	{
		alpha = 1.0f;
		if (dx < r && dy < r)
			alpha = aa_coverage(r - 1 - dx, r - 1 - dy, r);
		else if (dx >= rect->w - r && dy < r)
			alpha = aa_coverage(dx - (rect->w - r), r - 1 - dy, r);
		else if (dx < r && dy >= rect->h - r)
			alpha = aa_coverage(r - 1 - dx, dy - (rect->h - r), r);
		else if (dx >= rect->w - r && dy >= rect->h - r)
			alpha = aa_coverage(dx - (rect->w - r), dy - (rect->h - r), r);
		if (alpha <= 0.0f)
			continue ;
		fill = rect->color;
		if (alpha < 1.0f)
			fill = blend_u32(ui->get_color(ui->ctx, rect->x + dx, rect->y + dy),
					rect->color, alpha);
		ui->put_pixel(ui->ctx, rect->x + dx, rect->y + dy, fill);
	}
}

void	ui_rect(t_ui_context *ui, t_ui_base *rect)
{
	int32_t	r;
	int32_t	dy;

	r = rect->border.radius;
	dy = -1;
	while (++dy < rect->h)
		ui_rect_xloop(ui, rect, dy, r);
}
