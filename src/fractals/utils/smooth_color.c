/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 19:50:45 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/24 17:31:19 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** https://linas.org/art-gallery/escape/smooth.html
*/

void				smooth_color_pixel(t_pixel *pixel, long double iter,
					t_complex squares, t_fractal_params *params)
{
	iter = iter + 1.0 - log(log(squares.r + squares.i)) / log(params->pow_n);
	if (iter < 0.0)
		iter = 0;
	pixel->color = lerp_rgb(params->palette[
			(int)floor(iter) % params->palette_size],
		params->palette[
			(int)((floor(iter)) + 1) % params->palette_size],
		iter - floor(iter));
}
