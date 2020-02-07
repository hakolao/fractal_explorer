/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:03:22 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/07 14:59:20 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Reset frame color to original values
*/

static void			clear_frame(t_scene *scene)
{
	int		x;
	int		y;
	int		pixel;
	int		color;

	color = COLOR(0, 0, 0, 0);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel = y * scene->line_bytes + x * 4;
			scene->frame_buf[pixel] = BLUE(color);
			scene->frame_buf[pixel + 1] = GREEN(color);
			scene->frame_buf[pixel + 2] = RED(color);
			scene->frame_buf[pixel + 3] = ALPHA(color);
			x++;
		}
		y++;
	}
}

t_fractal_artist	artist_draw(enum e_fractal type)
{
	return ((t_fractal_artist[2]){
		draw_mandelbrot,
		draw_mandelbrot
	}[type]);
}

int					draw(t_scene *scene)
{
	mlx_clear_window(scene->mlx, scene->mlx_wdw);
	clear_frame(scene);
	artist_draw(scene->artist)(scene);
	mlx_put_image_to_window(scene->mlx, scene->mlx_wdw, scene->frame, 0, 0);
	draw_ui(scene);
	scene->redraw = FALSE;
	return (1);
}
