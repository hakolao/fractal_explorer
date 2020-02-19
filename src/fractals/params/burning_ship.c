/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:34:24 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/19 22:30:25 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int							burning_ship_params(t_fractal_params
							*fractal_params, t_scene *scene, int i)
{
	fractal_params->max_iter = MAX_ITER_INIT;
	fractal_params->zoom = 1.0;
	fractal_params->size = scene->screen_width *
		scene->screen_height / THREADS;
	fractal_params->center_x = BURNING_CENTER_X;
	fractal_params->center_y = BURNING_CENTER_Y;
	fractal_params->min_x = -2.0;
	fractal_params->max_x = 2.0;
	fractal_params->min_y = -2.0;
	fractal_params->max_y = 2.0;
	fractal_params->pow_n = 2.0;
	fractal_params->thread_i = i;
	fractal_params->cx_sign = 1;
	fractal_params->cy_sign = 1;
	fractal_params->width = scene->screen_width;
	fractal_params->height = scene->screen_height / THREADS;
	fractal_params->escape_time = burning_ship_escape;
	return (color_palette(fractal_params, scene->colors, 6,
			scene->palette_size) &&
		thread_render_params(fractal_params, scene, i));
}
