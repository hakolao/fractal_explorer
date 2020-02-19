/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 23:43:03 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/20 00:08:05 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		copy_scene_fractal_positions(t_fractal_params **dst,
			t_fractal_params **src)
{
	int		i;

	i = 0;
	while (i < THREADS)
	{
		dst[i]->zoom = src[i]->zoom;
		dst[i]->center_x = src[i]->center_x;
		dst[i]->center_y = src[i]->center_y;
		dst[i]->cx = src[i]->cx;
		dst[i]->cy = src[i]->cy;
		dst[i]->px = src[i]->px;
		dst[i]->py = src[i]->py;
		dst[i]->cx_sign = src[i]->cx_sign;
		dst[i]->cy_sign = src[i]->cy_sign;
		dst[i]->pow_n = src[i]->pow_n;
		dst[i]->max_iter = src[i]->max_iter;
		i++;
	}
}
