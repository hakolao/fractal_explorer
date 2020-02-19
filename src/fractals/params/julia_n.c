/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:35:31 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/19 15:37:00 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int							julia_n_params(t_fractal_params
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
	fractal_params->pow_n = 3.0;
	fractal_params->cx = -0.7;
	fractal_params->cy = 0.27015;
	fractal_params->thread_i = i;
	fractal_params->cx_sign = 1;
	fractal_params->cy_sign = 1;
	fractal_params->width = WIDTH;
	fractal_params->height = HEIGHT / THREADS;
	fractal_params->escape_time = julia_n_escape;
	return (color_palette(fractal_params, scene->colors, 6,
			scene->palette_size) &&
		thread_render_params(fractal_params, scene, i));
}
