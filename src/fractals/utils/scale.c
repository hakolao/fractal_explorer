/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:28:37 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/19 23:10:17 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Maps incoming pixel between
** fractal complex plane range.
*/

t_complex		scaled_xy(t_complex c,
				t_fractal_params *params, int px, int py)
{
	long double	min_x0;
	long double	min_y0;
	long double	max_x0;
	long double	max_y0;

	min_x0 = params->min_x;
	max_x0 = params->max_y;
	min_y0 = params->min_y;
	max_y0 = params->max_y;
	c.r = (min_x0 + px * (max_x0 - min_x0) / params->width) /
		params->zoom + params->center_x;
	c.i = (min_y0 + py * (max_y0 - min_y0) /
		(params->height * THREADS)) /
		params->zoom + params->center_y;
	return (c);
}
