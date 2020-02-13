/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:39:55 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/13 17:59:36 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			color_julia_pixel(t_pixel *pixel, long double iter,
					long double *r_i_z_pow, t_fractal_params *params)
{
	if ((int)params->pow_n % 2 == 1)
	{
		pixel->color = params->color_palette[(int)iter];
		return ;
	}
	iter = iter + 2.0 - log(log(r_i_z_pow[0] +
		r_i_z_pow[1])) / log(params->pow_n);
	pixel->color = lerp_rgb(params->color_palette[
			(int)floor(iter) % params->palette_size],
		params->color_palette[
			(int)((floor(iter)) + 1) % params->palette_size],
		iter - floor(iter));
}

static int			escape_time(long double *zx_zy, t_fractal_params *params,
					long double *r_i_z_pow)
{
	long double				xtemp;
	long double				iter;

	iter = 0.0;
	while (pow(zx_zy[0], 2) + pow(zx_zy[1], 2) <=
		params->r * params->r && iter < params->max_iter)
	{
		xtemp = pow(pow(zx_zy[0], 2) + pow(zx_zy[1], 2),
			(params->pow_n / 2.0)) * cos(params->pow_n *
				atan2(zx_zy[1], zx_zy[0])) + params->cx;
		zx_zy[1] = pow(pow(zx_zy[0], 2) + pow(zx_zy[1], 2),
			(params->pow_n / 2.0)) * sin(params->pow_n * atan2(zx_zy[1],
				zx_zy[0])) + params->cy;
		zx_zy[0] = xtemp;
		iter++;
	}
	r_i_z_pow[0] = pow(zx_zy[0], params->pow_n);
	r_i_z_pow[1] = pow(zx_zy[1], params->pow_n);
	r_i_z_pow[2] = pow((zx_zy[0] + zx_zy[1]), params->pow_n);
	return (iter);
}

static void			julia_n_pixel(int pixel_i, int px, int py, void *args)
{
	long double				*zx_zy;
	long double				*r_i_z_pow;
	long double				iter;
	t_fractal_params		*params;

	params = (t_fractal_params*)args;
	zx_zy = scaled_xy((long double[2]){0.0}, params, px, py);
	r_i_z_pow = (long double[3]){0.0};
	iter = escape_time(zx_zy, params, r_i_z_pow);
	set_pixel(params->pixels[pixel_i], px, py, 0);
	if (iter < params->max_iter)
		color_julia_pixel(params->pixels[pixel_i],
			iter, r_i_z_pow, params);
	plot_pixel_on_thread_frame(params, params->pixels[pixel_i]);
}

static void			julia_n_work(void *args)
{
	t_fractal_params *params;

	params = (t_fractal_params*)args;
	ft_pixel_foreach(params->pixel_bounds, args, julia_n_pixel);
}

void				draw_julia_n(t_scene *scene)
{
	work_parallel(THREADS, (void**)scene->fractal_params, julia_n_work);
}
