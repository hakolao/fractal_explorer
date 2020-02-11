/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:25:25 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/11 17:01:20 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			color_julia_pixel(t_pixel *pixel, long double iter,
					long double xy_sqr[2], t_fractal_params *params)
{
	iter = iter + 2.0 - log(log(xy_sqr[0] + xy_sqr[1])) / log(2.0);
	pixel->color = lerp_rgb(params->color_palette[
			(int)floor(iter) % params->palette_size],
		params->color_palette[
			(int)((floor(iter)) + 1) % params->palette_size],
		iter - floor(iter));
}

static void			julia_pixel(int pixel_i, int px, int py, void *args)
{
	long double				xy[2];
	long double				*x0_y0;
	long double				xy_sqr[2];
	long double				iter;
	t_fractal_params		*params;

	params = (t_fractal_params*)args;
	x0_y0 = scaled_xy((long double[2]){0.0}, params, px, py);
	xy[0] = x0_y0[0];
	xy[1] = x0_y0[1];
	iter = 0.0;
	while (xy_sqr[0] + xy_sqr[1] <= 16 &&
		iter < (params->max_iter))
	{
		xy_sqr[0] = xy[0] * xy[0];
		xy_sqr[1] = xy[1] * xy[1];
		xy[0] = xy_sqr[0] - xy_sqr[1] + params->jx;
		xy[1] = 2.0 * xy[0] * xy[1] + params->jy;
		iter++;
	}
	set_pixel(params->pixels[pixel_i], px, py, 0);
	if (iter < params->max_iter)
		color_julia_pixel(params->pixels[pixel_i], iter,
			xy_sqr, params);
	plot_pixel_on_thread_frame(params, params->pixels[pixel_i]);
}

static void			julia_work(void *args)
{
	t_fractal_params *params;

	params = (t_fractal_params*)args;
	ft_pixel_foreach(params->pixel_bounds, args, julia_pixel);
}

void				draw_julia(t_scene *scene)
{
	work_parallel(THREADS, (void**)scene->fractal_params, julia_work);
}
