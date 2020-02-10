/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:18:55 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/10 15:11:21 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				lerp_rgb(int start, int end, double gradient_mul)
{
	int r_diff;
	int	g_diff;
	int	b_diff;

	if (gradient_mul == 0.0)
		return (start);
	r_diff = RED(start) - RED(end);
	g_diff = GREEN(start) - GREEN(end);
	b_diff = BLUE(start) - BLUE(end);
	return (COLOR(
			r_diff > 0 ? RED(start) - (int)(gradient_mul * ft_abs(r_diff)) :
				RED(start) + (int)(gradient_mul * ft_abs(r_diff)),
			g_diff > 0 ? GREEN(start) - (int)(gradient_mul * ft_abs(g_diff)) :
				GREEN(start) + (int)(gradient_mul * ft_abs(g_diff)),
			b_diff > 0 ? BLUE(start) - (int)(gradient_mul * ft_abs(b_diff)) :
				BLUE(start) + (int)(gradient_mul * ft_abs(b_diff)), 0));
}

void			plot_pixel_on_thread_frame(t_fractal_params *params,
				t_pixel *pixel)
{
	int	pixel_i;
	int	size;

	size = params->width * params->height;
	pixel_i = (pixel->y * WIDTH * 4) +
		(pixel->x * 4) - params->thread_i * size * 4;
	if (pixel_i > 0 && pixel_i < size * 4)
	{
		params->frame_buf[pixel_i + 0] = BLUE(pixel->color);
		params->frame_buf[pixel_i + 1] = GREEN(pixel->color);
		params->frame_buf[pixel_i + 2] = RED(pixel->color);
		params->frame_buf[pixel_i + 3] = ALPHA(pixel->color);
	}
}

void			set_pixel(t_pixel *pixel, int x, int y, int color)
{
	pixel->color = color;
	pixel->x = x;
	pixel->y = y;
}
