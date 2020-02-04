/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:18:55 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/04 12:46:34 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				lerp_rgb(int start, int end, double gradient_mul)
{
	int r_diff;
	int	g_diff;
	int	b_diff;

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

void			plot_pixel(t_scene *scene, int x, int y, int color)
{
	int	pixel;

	pixel = (y * scene->line_bytes) + (x * 4);
	if (pixel > 0 && pixel < HEIGHT * WIDTH * 4)
	{
		scene->frame_buf[pixel + 0] = BLUE(color);
		scene->frame_buf[pixel + 1] = GREEN(color);
		scene->frame_buf[pixel + 2] = RED(color);
		scene->frame_buf[pixel + 3] = ALPHA(color);
	}
}
