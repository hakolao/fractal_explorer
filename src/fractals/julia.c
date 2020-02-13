/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 16:25:25 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/13 23:51:25 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** https://en.wikipedia.org/wiki/Julia_set
*/

static double		escape_time(t_complex z, t_complex *squares,
					t_fractal_params *params)
{
	long double				xtemp;
	long double				iter;

	iter = 0.0;
	while (z.x * z.x + z.y *z.y <=
		params->r * params->r && iter < params->max_iter)
	{
		xtemp = z.x * z.x - z.y * z.y;
		z.y = 2.0 * z.x * z.y + params->cy;
		z.x = xtemp + params->cx;
		iter++;
	}
	squares->x = z.x * z.x;
	squares->y = z.y * z.y;
	return (iter);
}

static void			julia_pixel(int pixel_i, int px, int py, void *args)
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
