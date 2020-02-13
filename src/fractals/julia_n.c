/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:39:55 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/13 23:24:48 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double		escape_time(t_complex z, t_complex *powers,
					t_fractal_params *params)
{
	long double				iter;
	long double				xtemp;

	iter = 0.0;
	while (z.x * z.x + z.y * z.y <= 16 && iter < params->max_iter)
	{
		xtemp = pow(z.x * z.x + z.y * z.y, (params->pow_n / 2.0)) *
			cos(params->pow_n * atan2(z.y, z.x)) + params->cx;
		z.y = pow(z.x * z.x + z.y * z.y, (params->pow_n / 2.0)) *
			sin(params->pow_n * atan2(z.y, z.x)) + params->cy;
		z.x = xtemp;
		iter++;
	}
	powers->x = pow(z.x, params->pow_n);
	powers->y = pow(z.y, params->pow_n);
	return (iter);
}

static void			julia_n_pixel(int pixel_i, int px, int py, void *args)
{
	t_complex				z;
	t_complex				powers;
	long double				iter;
	t_fractal_params		*params;

	params = (t_fractal_params*)args;
	z = scaled_xy((t_complex){0.0, 0.0}, params, px, py);
	powers = (t_complex){0.0, 0.0};
	iter = escape_time(z, &powers, params);
	set_pixel(params->pixels[pixel_i], px, py, 0);
	if (iter < params->max_iter)
		color_julia_n_pixel(params->pixels[pixel_i], iter,
			powers, params);
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
