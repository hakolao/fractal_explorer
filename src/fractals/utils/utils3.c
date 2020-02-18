/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:31:15 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/18 14:34:31 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			flip_cx_sign(t_scene *scene)
{
	int		i;

	i = 0;
	while (i < THREADS)
	{
		scene->fractal_params[i]->cx_sign = -1 *
			scene->fractal_params[i]->cx_sign;
		i++;
	}
	return (0);
}

int			flip_cy_sign(t_scene *scene)
{
	int		i;

	i = 0;
	while (i < THREADS)
	{
		scene->fractal_params[i]->cy_sign = -1 *
			scene->fractal_params[i]->cy_sign;
		i++;
	}
	return (0);
}

int			move_px_py(t_scene *scene, int mouse_x,
			int mouse_y)
{
	int			i;
	t_complex	p;

	i = 0;
	p = scaled_xy((t_complex){0.0, 0.0}, scene->fractal_params[i],
		mouse_x, mouse_y);
	while (i < THREADS)
	{
		scene->fractal_params[i]->px = p.r;
		scene->fractal_params[i]->py = p.i;
		i++;
	}
	return (1);
}
