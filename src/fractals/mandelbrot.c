/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:20:06 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/19 22:54:48 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				mandelbrot_pixel(int pixel_i, int px, int py, void *args)
{
	t_complex				squares;
	t_complex				c;
	t_complex				z;
	long double				iter;
	t_fractal_params		*params;

	params = (t_fractal_params*)args;
	squares = (t_complex){0.0, 0.0};
	z = (t_complex){0.0, 0.0};
	c = scaled_xy((t_complex){0.0, 0.0}, params, px, py);
	iter = params->escape_time((t_complex){0.0, 0.0}, c, &squares, params);
	set_pixel(params->pixels[pixel_i], px, py, 0);
	if (iter < params->max_iter)
		smooth_color_pixel(params->pixels[pixel_i], iter, squares, params);
	plot_pixel_on_thread_frame(params, params->pixels[pixel_i]);
}

static void			mandelbrot_work(void *args)
{
	t_fractal_params *params;

	params = (t_fractal_params*)args;
	ft_pixel_foreach(params->pixel_bounds, args, mandelbrot_pixel);
}

void				draw_mandelbrot(t_scene *scene)
{
	work_parallel(THREADS, (void**)scene->fractal_params, mandelbrot_work);
}
