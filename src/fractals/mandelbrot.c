/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 10:46:22 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/04 15:29:53 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		plot_mandelbrot(t_pixel pixel, void *params)
{
	double		x;
	double		y;
	double		x0;
	double		y0;
	double		rsquare;
	double		isquare;
	double		zsquare;
	// double		log_zn;
	t_scene		*scene;
	double		iter;

	scene = (t_scene*)params;
	x0 = ft_lmap_double((double)pixel.x,
		(double[2]){0, (double)WIDTH}, (double[2]){-2.5, 1.0});
	y0 = ft_lmap_double((double)pixel.y,
		(double[2]){0, (double)HEIGHT}, (double[2]){-1.0, 1.0});
    x = 0.0;
    y = 0.0;
	rsquare = 0.0;
	isquare = 0.0;
	zsquare = 0.0;
    iter = 0.0;
	while (rsquare + isquare <= (1 << 16) && iter < (scene->max_iter))
	{
		x = rsquare - isquare + x0;
		y = zsquare - rsquare + y0;
		rsquare = x * x;
		isquare = y * y;
		zsquare = (x + y) * (x + y);
		iter++;

		plot_pixel(scene, pixel.x, pixel.y, scene->color_palette[(int)floor(iter)]);
		// if (iter < scene->max_iter)
		// {
		// 	log_zn = log(rsquare + isquare) / 2.0;
		// 	iter = iter + 1.0 - log(log_zn / log(2.0)) / log(2.0);		
		// }
		// plot_pixel(scene, pixel.x, pixel.y, lerp_rgb(
		// 	scene->color_palette[(int)floor(iter)],
		// 	scene->color_palette[(int)(floor(iter) + 1.0)],
		// 	iter - floor(iter)));
	}
}

void		draw_mandelbrot(t_scene *scene)
{
	ft_pixel_foreach((t_pixels){.x_start = 0, .x_end = WIDTH,
		.y_start = 0, .y_end = HEIGHT}, 
		scene,
		plot_mandelbrot);
}