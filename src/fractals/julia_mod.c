/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_mod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 15:06:00 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/14 14:25:56 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Modified version of julia set with abs values &
** flippable cx, cy signs :). Creates quite fancy
** fractals.
*/

static double		escape_time(t_complex z, t_complex *squares,
					t_fractal_params *params)
{
	long double				iter;

	iter = 0.0;
	while (squares->x + squares->y <=
		params->r * params->r && iter < params->max_iter)
	{
		z.y = 2 * ft_abs_long_double(z.y * z.x) +
			params->cx_sign * params->cy;
		z.x = ft_abs_long_double(squares->x - squares->y) +
			params->cy_sign * params->cx;
		squares->x = z.x * z.x;
		squares->y = z.y * z.y;
		iter++;
	}
	return (iter);
}

static void			julia_mod_pixel(int pixel_i, int px, int py, void *args)
{
	t_complex				z;
	t_complex				squares;
	long double				iter;
	t_fractal_params		*params;

	params = (t_fractal_params*)args;
	z = scaled_xy((t_complex){0.0, 0.0}, params, px, py);
	squares = (t_complex){z.x * z.x, z.y * z.y};
	iter = escape_time(z, &squares, params);
	set_pixel(params->pixels[pixel_i], px, py, 0);
	if (iter < params->max_iter)
		color_julia_pixel(params->pixels[pixel_i],
			iter, squares, params);
	plot_pixel_on_thread_frame(params, params->pixels[pixel_i]);
}

static void			julia_mod_work(void *args)
{
	t_fractal_params *params;

	params = (t_fractal_params*)args;
	ft_pixel_foreach(params->pixel_bounds, args, julia_mod_pixel);
}

void				draw_julia_mod(t_scene *scene)
{
	work_parallel(THREADS, (void**)scene->fractal_params, julia_mod_work);
}
