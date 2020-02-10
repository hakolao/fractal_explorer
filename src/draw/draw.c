/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:03:22 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/10 15:11:48 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Reset frame color to original values
*/

static void			clear_frame(char *frame_buf,
					int line_bytes, int height, int width)
{
	int		x;
	int		y;
	int		pixel;
	int		color;

	color = COLOR(255, 0, 0, 0);
	y = 0;
	while (y < height)
	{
		x = 0;
		while (x < width)
		{
			pixel = y * line_bytes + x * 4;
			frame_buf[pixel] = BLUE(color);
			frame_buf[pixel + 1] = GREEN(color);
			frame_buf[pixel + 2] = RED(color);
			frame_buf[pixel + 3] = ALPHA(color);
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

static void			clear_thread_frames(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < THREADS)
	{
		clear_frame(scene->fractal_params[i]->frame_buf,
			scene->line_bytes, HEIGHT / THREADS, WIDTH);
		i++;
	}
}

static void			place_thread_frames(t_scene *scene)
{
	int	i;

	i = 0;
	while (i < THREADS)
	{
		mlx_put_image_to_window(scene->mlx, scene->mlx_wdw,
			scene->fractal_params[i]->frame, 0, i * HEIGHT / THREADS);
		i++;
	}
}

int					draw(t_scene *scene)
{
	mlx_clear_window(scene->mlx, scene->mlx_wdw);
	clear_thread_frames(scene);
	artist_draw(scene->artist)(scene);
	place_thread_frames(scene);
	draw_ui(scene);
	scene->redraw = FALSE;
	return (1);
}
