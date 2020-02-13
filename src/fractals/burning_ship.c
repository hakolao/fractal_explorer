/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:49:38 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/13 12:56:08 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			color_burning_ship_pixel(t_pixel *pixel, long double iter,
					long double r_i_z_square[3], t_fractal_params *params)
{
	long double				log_zn;

	log_zn = log(r_i_z_square[0] + r_i_z_square[1]) / 2.0;
	iter = iter + 1.0 - log(log_zn / log(2.0)) / log(2.0);
	pixel->color = lerp_rgb(params->color_palette[
			(int)floor(iter) % params->palette_size],
		params->color_palette[
			(int)((floor(iter)) + 1) % params->palette_size],
		iter - floor(iter));
}

static double		escape_time(long double *r_i_z_square, long double *cx_cy,
					long double max_iter)
{
	long double				zx_zy[2];
	long double				iter;

	iter = 0.0;
	while (r_i_z_square[0] + r_i_z_square[1] <= 16 &&
		iter < max_iter)
	{
		zx_zy[0] = ft_abs_long_double(r_i_z_square[0] -
			r_i_z_square[1] + cx_cy[0]);
		zx_zy[1] = ft_abs_long_double(r_i_z_square[2] - r_i_z_square[0] -
			r_i_z_square[1] + cx_cy[1]);
		r_i_z_square[0] = zx_zy[0] * zx_zy[0];
		r_i_z_square[1] = zx_zy[1] * zx_zy[1];
		r_i_z_square[2] = (zx_zy[0] + zx_zy[1]) * (zx_zy[0] + zx_zy[1]);
		iter++;
	}
	return (iter);
}

static void			burning_ship_pixel(int pixel_i, int px, int py, void *args)
{
	long double				*cx_cy;
	long double				*r_i_z_square;
	long double				iter;
	t_fractal_params		*params;

	params = (t_fractal_params*)args;
	r_i_z_square = (long double[3]){0.0};
	cx_cy = scaled_xy((long double[2]){0.0}, params, px, py);
	iter = escape_time(r_i_z_square, cx_cy, params->max_iter);
	set_pixel(params->pixels[pixel_i], px, py, 0);
	if (iter < params->max_iter)
		color_burning_ship_pixel(params->pixels[pixel_i], iter,
			r_i_z_square, params);
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
