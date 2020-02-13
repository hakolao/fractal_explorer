/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:08:02 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/13 23:26:48 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static double		escape_time(t_complex c, t_complex *powers,
					long double max_iter, long double pow_n)
{
	long double				iter;
	long double				xtemp;
	t_complex				z;

	iter = 0.0;
	z = c;
	while (z.x * z.x + z.y * z.y <= 16 && iter < max_iter)
	{
		xtemp = pow(z.x * z.x + z.y * z.y, (pow_n / 2.0)) *
			cos(pow_n * atan2(z.y, z.x)) + c.x;
		z.y = pow(z.x * z.x + z.y * z.y, (pow_n / 2.0)) *
			sin(pow_n * atan2(z.y, z.x)) + c.y;
		z.x = xtemp;
		iter++;
	}
	powers->x = pow(z.x, pow_n);
	powers->y = pow(z.y, pow_n);
	return (iter);
}

static void			mandelbrot_n_pixel(int pixel_i, int px,
					int py, void *args)
{
	t_complex				powers;
	t_complex				c;
	long double				iter;
	t_fractal_params		*params;

	params = (t_fractal_params*)args;
	powers = (t_complex){0.0, 0.0};
	c = scaled_xy((t_complex){0.0, 0.0}, params, px, py);
	iter = escape_time(c, &powers, params->max_iter, params->pow_n);
	set_pixel(params->pixels[pixel_i], px, py, 0);
	if (iter < params->max_iter)
		color_mandelbrot_n_pixel(params->pixels[pixel_i], iter,
			powers, params);
	plot_pixel_on_thread_frame(params, params->pixels[pixel_i]);
}

static void			mandelbrot_n_work(void *args)
{
	t_fractal_params *params;

	params = (t_fractal_params*)args;
	ft_pixel_foreach(params->pixel_bounds, args, mandelbrot_n_pixel);
}

void				draw_mandelbrot_n(t_scene *scene)
{
	work_parallel(THREADS, (void**)scene->fractal_params,
		mandelbrot_n_work);
}
