/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:03:22 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/04 16:37:12 by ohakola          ###   ########.fr       */
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

	// color = COLOR(scene->col_r, scene->col_g, scene->col_b, scene->col_a);
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			color = scene->color_palette[x * scene->max_iter / WIDTH];
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

/*
** Draw pipeline to draw fdf
*/

int					draw(t_scene *scene)
{
	mlx_clear_window(scene->mlx, scene->mlx_wdw);
	clear_frame(scene);
	// draw_mandelbrot(scene);
	mlx_put_image_to_window(scene->mlx, scene->mlx_wdw, scene->frame, 0, 0);
	// draw_ui(scene);
	scene->redraw = FALSE;
	return (1);
}
