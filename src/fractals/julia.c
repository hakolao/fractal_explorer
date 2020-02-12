/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:25:25 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/12 16:36:44 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			color_julia_pixel(t_pixel *pixel, long double iter,
					long double *zx_zy, t_fractal_params *params)
{
	iter = iter + 2.0 - log(log(zx_zy[0] * zx_zy[0] +
		zx_zy[1] * zx_zy[1])) / log(2.0);
	pixel->color = lerp_rgb(params->color_palette[
			(int)floor(iter) % params->palette_size],
		params->color_palette[
			(int)((floor(iter)) + 1) % params->palette_size],
		iter - floor(iter));
}

static int			escape_time(long double *zx_zy, t_fractal_params *params)
{
	long double				x_temp;
	long double				iter;

	iter = 0.0;
	while (zx_zy[0] * zx_zy[0] + zx_zy[1] * zx_zy[1] <=
		params->r * params->r && iter < params->max_iter)
	{
		x_temp = zx_zy[0] * zx_zy[0] - zx_zy[1] * zx_zy[1];
		zx_zy[1] = 2.0 * zx_zy[0] * zx_zy[1] + params->cy;
		zx_zy[0] = x_temp + params->cx;
		iter++;
	}
	return (iter);
}

static void			julia_pixel(int pixel_i, int px, int py, void *args)
{
	long double				*zx_zy;
	long double				iter;
	t_fractal_params		*params;

	params = (t_fractal_params*)args;
	zx_zy = scaled_xy((long double[2]){0.0}, params, px, py);
	iter = escape_time(zx_zy, params);
	set_pixel(params->pixels[pixel_i], px, py, 0);
	if (iter < params->max_iter)
		color_julia_pixel(params->pixels[pixel_i],
			iter, zx_zy, params);
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
