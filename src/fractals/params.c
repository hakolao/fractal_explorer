/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:13:05 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/13 16:30:26 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int							mandelbrot_params(t_fractal_params
							*fractal_params, t_scene *scene, int i)
{
	fractal_params->max_iter = MAX_ITER_INIT;
	fractal_params->zoom = 1.0;
	fractal_params->size = PIXELS;
	fractal_params->center_x = MANDEL_CENTER_X;
	fractal_params->center_y = MANDEL_CENTER_Y;
	fractal_params->min_x = -2.0;
	fractal_params->max_x = 2.0;
	fractal_params->min_y = -2.0;
	fractal_params->max_y = 2.0;
	fractal_params->thread_i = i;
	fractal_params->width = WIDTH;
	fractal_params->height = HEIGHT / THREADS;
	if (!color_palette(fractal_params, scene->colors, 6,
			scene->palette_size) ||
		!thread_render_params(fractal_params, scene, i))
		return (FALSE);
	return (TRUE);
}

int							mandelbrot_n_params(t_fractal_params
							*fractal_params, t_scene *scene, int i)
{
	fractal_params->max_iter = MAX_ITER_INIT;
	fractal_params->zoom = 1.0;
	fractal_params->size = PIXELS;
	fractal_params->center_x = 0.0;
	fractal_params->center_y = 0.0;
	fractal_params->min_x = -2.0;
	fractal_params->max_x = 2.0;
	fractal_params->min_y = -2.0;
	fractal_params->max_y = 2.0;
	fractal_params->thread_i = i;
	fractal_params->width = WIDTH;
	fractal_params->height = HEIGHT / THREADS;
	fractal_params->pow_n = 3.0;
	if (!color_palette(fractal_params, scene->colors, 6,
			scene->palette_size) ||
		!thread_render_params(fractal_params, scene, i))
		return (FALSE);
	return (TRUE);
}

int							julia_params(t_fractal_params
							*fractal_params, t_scene *scene, int i)
{
	fractal_params->max_iter = MAX_ITER_INIT;
	fractal_params->zoom = 1.0;
	fractal_params->size = PIXELS;
	fractal_params->center_x = JULIA_CENTER_X;
	fractal_params->center_y = JULIA_CENTER_Y;
	fractal_params->r = 2.0;
	fractal_params->min_x = -fractal_params->r;
	fractal_params->max_x = fractal_params->r;
	fractal_params->min_y = -fractal_params->r;
	fractal_params->max_y = fractal_params->r;
	fractal_params->cx = -0.7;
	fractal_params->cy = 0.27015;
	fractal_params->thread_i = i;
	fractal_params->width = WIDTH;
	fractal_params->height = HEIGHT / THREADS;
	if (!color_palette(fractal_params, scene->colors, 6,
			scene->palette_size) ||
		!thread_render_params(fractal_params, scene, i))
		return (FALSE);
	return (TRUE);
}

int							burning_ship_params(t_fractal_params
							*fractal_params, t_scene *scene, int i)
{
	fractal_params->max_iter = MAX_ITER_INIT;
	fractal_params->zoom = 1.0;
	fractal_params->size = PIXELS;
	fractal_params->center_x = BURNING_CENTER_X;
	fractal_params->center_y = BURNING_CENTER_Y;
	fractal_params->min_x = -2.0;
	fractal_params->max_x = 2.0;
	fractal_params->min_y = -2.0;
	fractal_params->max_y = 2.0;
	fractal_params->thread_i = i;
	fractal_params->width = WIDTH;
	fractal_params->height = HEIGHT / THREADS;
	if (!color_palette(fractal_params, scene->colors, 6,
			scene->palette_size) ||
		!thread_render_params(fractal_params, scene, i))
		return (FALSE);
	return (TRUE);
}

t_fractal_param_f			select_params(enum e_fractal type)
{
	return ((t_fractal_param_f[4]){
		mandelbrot_params,
		julia_params,
		burning_ship_params,
		mandelbrot_n_params
	}[type]);
}
