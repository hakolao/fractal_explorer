/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_julia.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:34:24 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/19 22:30:39 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int							burning_julia_params(t_fractal_params
							*fractal_params, t_scene *scene, int i)
{
	fractal_params->max_iter = MAX_ITER_INIT;
	fractal_params->zoom = 1.0;
	fractal_params->size = scene->screen_width *
		scene->screen_height / THREADS;
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
	fractal_params->cx_sign = 1;
	fractal_params->cy_sign = 1;
	fractal_params->thread_i = i;
	fractal_params->width = scene->screen_width;
	fractal_params->height = scene->screen_height / THREADS;
	fractal_params->escape_time = burning_julia_escape;
	return (color_palette(fractal_params, scene->colors, 6,
			scene->palette_size) &&
		thread_render_params(fractal_params, scene, i));
}
