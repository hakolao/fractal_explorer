/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:03:22 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/10 16:34:50 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fractal_artist	artist_draw(enum e_fractal type)
{
	return ((t_fractal_artist[2]){
		draw_mandelbrot,
		draw_mandelbrot
	}[type]);
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
	artist_draw(scene->artist)(scene);
	place_thread_frames(scene);
	draw_ui(scene);
	scene->redraw = FALSE;
	return (1);
}
