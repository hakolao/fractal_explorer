/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nova.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 17:33:50 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/18 13:41:54 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** https://fractalfoundation.org/OFC/OFC-5-5.html
*/

static void			nova_pixel(int pixel_i, int px, int py, void *args)
{
	t_complex				powers;
	t_complex				c;
	t_complex				z;
	long double				iter;
	t_fractal_params		*params;

	params = (t_fractal_params*)args;
	powers = (t_complex){0.0, 0.0};
	z = (t_complex){0.0, 0.0};
	c = scaled_xy((t_complex){0.0, 0.0}, params, px, py);
	iter = nova_escape((t_complex){0.0, 0.0}, c, &powers, params);
	set_pixel(params->pixels[pixel_i], px, py, 0);
	if (iter < params->max_iter)
		color_mandelbrot_pixel(params->pixels[pixel_i], iter, powers, params);
	plot_pixel_on_thread_frame(params, params->pixels[pixel_i]);
}

static void			nova_work(void *args)
{
	t_fractal_params *params;

	params = (t_fractal_params*)args;
	ft_pixel_foreach(params->pixel_bounds, args, nova_pixel);
}

void				draw_nova(t_scene *scene)
{
	work_parallel(THREADS, (void**)scene->fractal_params, nova_work);
}
