/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:49:38 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/18 17:59:06 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			burning_ship_pixel(int pixel_i, int px, int py, void *args)
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
	iter = burning_ship_escape(z, c, &squares, params);
	set_pixel(params->pixels[pixel_i], px, py, 0);
	if (iter < params->max_iter)
		smooth_color_pixel(params->pixels[pixel_i], iter,
			squares, params);
	plot_pixel_on_thread_frame(params, params->pixels[pixel_i]);
}

static void			burning_ship_work(void *args)
{
	t_fractal_params *params;

	params = (t_fractal_params*)args;
	ft_pixel_foreach(params->pixel_bounds, args, burning_ship_pixel);
}

void				draw_burning_ship(t_scene *scene)
{
	work_parallel(THREADS, (void**)scene->fractal_params,
		burning_ship_work);
}
