/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:29:37 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/13 14:24:22 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int						zoom(t_scene *scene, long double amount)
{
	int	i;

	i = 0;
	while (i < THREADS)
	{
		scene->fractal_params[i]->zoom *= amount;
		scene->fractal_params[i]->max_iter += amount > 1 ? 1 : -1;
		i++;
	}
	return (0);
}

int						center_to(t_scene *scene, long double mouse_x,
						long double mouse_y)
{
	int			i;
	long double	*new_x_y;

	i = 0;
	new_x_y = scaled_xy((long double[2]){0.0}, scene->fractal_params[i],
		mouse_x, mouse_y);
	while (i < THREADS)
	{
		scene->fractal_params[i]->center_x =
			new_x_y[0];
		scene->fractal_params[i]->center_y =
			new_x_y[1];
		i++;
	}
	return (0);
}

int						change_iters(t_scene *scene, long double amount)
{
	int		i;

	i = 0;
	while (i < THREADS)
	{
		scene->fractal_params[i]->max_iter += amount;
		i++;
	}
	return (0);
}

long double				*scaled_xy(long double *cx_cy,
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
	cx_cy[0] = (min_x0 + px * (max_x0 - min_x0) / WIDTH) /
		params->zoom + params->center_x;
	cx_cy[1] = (min_y0 + py * (max_y0 - min_y0) / HEIGHT) /
		params->zoom + params->center_y;
	return (cx_cy);
}

int						move_cx_cy(t_scene *scene, int mouse_x,
						int mouse_y)
{
	int			i;
	long double	*cx_cy;

	i = 0;
	cx_cy = scaled_xy((long double[2]){0.0}, scene->fractal_params[i],
		mouse_x, mouse_y);
	while (i < THREADS)
	{
		scene->fractal_params[i]->cx = cx_cy[0];
		scene->fractal_params[i]->cy = cx_cy[1];
		i++;
	}
	return (1);
}
