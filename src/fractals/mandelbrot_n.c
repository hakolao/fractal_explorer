/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:08:02 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/13 17:48:19 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			color_inverse_mandelbrot_pixel(t_pixel *pixel,
					long double iter, long double r_i_z_pow[3],
					t_fractal_params *params)
{
	if ((int)params->pow_n % 2 == 1)
	{
		pixel->color = params->color_palette[(int)iter];
		return ;
	}
	iter = iter - log(log(
		pow((r_i_z_pow[0] + r_i_z_pow[1]), 1 / params->pow_n)) /
		log(params->palette_size)) / log(params->pow_n);
	pixel->color = lerp_rgb(params->color_palette[
			(int)floor(iter) % params->palette_size],
		params->color_palette[
			(int)((floor(iter)) + 1) % params->palette_size],
		iter - floor(iter));
}

static double		escape_time(long double *r_i_z_pow, long double *cx_cy,
					long double max_iter, long double pow_n)
{
	long double				zx_zy[2];
	long double				xtemp;
	long double				iter;

	iter = 0.0;
	zx_zy[0] = cx_cy[0];
	zx_zy[1] = cx_cy[1];
	while (pow(zx_zy[0], 2) + pow(zx_zy[1], 2) <= 16 &&
		iter < max_iter)
	{
		xtemp = pow(pow(zx_zy[0], 2) + pow(zx_zy[1], 2),
			(pow_n / 2.0)) * cos(pow_n * atan2(zx_zy[1], zx_zy[0])) + cx_cy[0];
		zx_zy[1] = pow(pow(zx_zy[0], 2) + pow(zx_zy[1], 2),
			(pow_n / 2.0)) * sin(pow_n * atan2(zx_zy[1], zx_zy[0])) + cx_cy[1];
		zx_zy[0] = xtemp;
		iter++;
	}
	r_i_z_pow[0] = pow(zx_zy[0], pow_n);
	r_i_z_pow[1] = pow(zx_zy[1], pow_n);
	r_i_z_pow[2] = pow((zx_zy[0] + zx_zy[1]), pow_n);
	return (iter);
}

static void			inverse_mandelbrot_pixel(int pixel_i, int px,
					int py, void *args)
{
	long double				*cx_cy;
	long double				*r_i_z_pow;
	long double				iter;
	t_fractal_params		*params;

	params = (t_fractal_params*)args;
	r_i_z_pow = (long double[3]){0.0};
	cx_cy = scaled_xy((long double[2]){0.0}, params, px, py);
	iter = escape_time(r_i_z_pow, cx_cy, params->max_iter, params->pow_n);
	set_pixel(params->pixels[pixel_i], px, py, 0);
	if (iter < params->max_iter)
		color_inverse_mandelbrot_pixel(params->pixels[pixel_i], iter,
			r_i_z_pow, params);
	plot_pixel_on_thread_frame(params, params->pixels[pixel_i]);
}

static void			inverse_mandelbrot_work(void *args)
{
	t_fractal_params *params;

	params = (t_fractal_params*)args;
	ft_pixel_foreach(params->pixel_bounds, args, inverse_mandelbrot_pixel);
}

void				draw_mandelbrot_n(t_scene *scene)
{
	work_parallel(THREADS, (void**)scene->fractal_params,
		inverse_mandelbrot_work);
}
