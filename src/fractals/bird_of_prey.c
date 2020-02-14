/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bird_of_prey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:06:26 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/14 13:10:53 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** https://www.app13x.com/MacShipTrek.html
*/

static double		escape_time(t_complex z_init, t_complex c,
					t_complex *squares, long double max_iter)
{
	long double				z_sqr;
	long double				iter;
	t_complex				z;

	iter = 0.0;
	z = z_init;
	while (squares->x + squares->y <= 16 && iter < max_iter)
	{
		z.x = ft_abs_long_double(squares->x - squares->y + c.x);
		z.y = ft_abs_long_double(z_sqr - squares->x - squares->y + c.y);
		squares->x = z.x * z.x;
		squares->y = z.y * z.y;
		z_sqr = (z.x + z.y) * (z.x + z.y);
		iter++;
	}
	return (iter);
}

static void			bird_of_prey_pixel(int pixel_i, int px, int py, void *args)
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
	iter = escape_time(z, c, &squares, params->max_iter);
	set_pixel(params->pixels[pixel_i], px, py, 0);
	if (iter < params->max_iter)
		color_mandelbrot_pixel(params->pixels[pixel_i], iter,
			squares, params);
	plot_pixel_on_thread_frame(params, params->pixels[pixel_i]);
}

static void			bird_of_prey_work(void *args)
{
	t_fractal_params *params;

	params = (t_fractal_params*)args;
	ft_pixel_foreach(params->pixel_bounds, args, bird_of_prey_pixel);
}

void				draw_bird_of_prey(t_scene *scene)
{
	work_parallel(THREADS, (void**)scene->fractal_params,
		bird_of_prey_work);
}
