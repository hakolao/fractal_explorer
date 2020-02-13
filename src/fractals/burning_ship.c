/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 11:49:38 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/13 23:07:40 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			color_burning_ship_pixel(t_pixel *pixel, long double iter,
					t_complex squares, t_fractal_params *params)
{
	iter = iter + 1.0 - log(log(squares.x + squares.y) /
		2.0 / log(2.0)) / log(2.0);
	pixel->color = lerp_rgb(params->color_palette[
			(int)floor(iter) % params->palette_size],
		params->color_palette[
			(int)((floor(iter)) + 1) % params->palette_size],
		iter - floor(iter));
}

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

static void			burning_ship_pixel(int pixel_i, int px, int py, void *args)
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
		color_burning_ship_pixel(params->pixels[pixel_i], iter, squares, params);
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
