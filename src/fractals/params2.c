/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 13:08:14 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/14 13:49:56 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int							bird_of_prey_params(t_fractal_params
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
	fractal_params->pow_n = 2.0;
	fractal_params->thread_i = i;
	fractal_params->width = WIDTH;
	fractal_params->height = HEIGHT / THREADS;
	if (!color_palette(fractal_params, scene->colors, 6,
			scene->palette_size) ||
		!thread_render_params(fractal_params, scene, i))
		return (FALSE);
	return (TRUE);
}

int							phoenix_params(t_fractal_params
							*fractal_params, t_scene *scene, int i)
{
	fractal_params->max_iter = MAX_ITER_INIT;
	fractal_params->zoom = 1.0;
	fractal_params->size = PIXELS;
	fractal_params->center_x = 0.0;
	fractal_params->center_y = 0.0;
	fractal_params->r = 2.0;
	fractal_params->min_x = -fractal_params->r;
	fractal_params->max_x = fractal_params->r;
	fractal_params->min_y = -fractal_params->r;
	fractal_params->max_y = fractal_params->r;
	fractal_params->cx = -0.7;
	fractal_params->cy = 0.27015;
	fractal_params->pow_n = 2.0;
	fractal_params->thread_i = i;
	fractal_params->width = WIDTH;
	fractal_params->height = HEIGHT / THREADS;
	if (!color_palette(fractal_params, scene->colors, 6,
			scene->palette_size) ||
		!thread_render_params(fractal_params, scene, i))
		return (FALSE);
	return (TRUE);
}