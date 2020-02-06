/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:18:55 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/06 16:09:24 by ohakola          ###   ########.fr       */
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

void			plot_threaded_pixels(t_scene *scene)
{
	int				i;
	int				j;

	i = 0;
	while (i < THREADS)
	{
		j = -1;
		while (++j < scene->fractal_params[i]->size)
			plot_pixel(scene, scene->fractal_params[i]->pixels[j]->x,
				scene->fractal_params[i]->pixels[j]->y,
				scene->fractal_params[i]->pixels[j]->color);
		i++;
	}
}

void			set_pixel(t_pixel *pixel, int x, int y, int color)
{
	pixel->color = color;
	pixel->x = x;
	pixel->y = y;
}
