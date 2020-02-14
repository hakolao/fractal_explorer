/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:29:37 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/14 15:02:26 by ohakola          ###   ########.fr       */
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
	t_complex	new;

	i = 0;
	new = scaled_xy((t_complex){0.0, 0.0}, scene->fractal_params[i],
		mouse_x, mouse_y);
	while (i < THREADS)
	{
		scene->fractal_params[i]->center_x = new.x;
		scene->fractal_params[i]->center_y = new.y;
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

t_complex				scaled_xy(t_complex c,
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
	c.x = (min_x0 + px * (max_x0 - min_x0) / WIDTH) /
		params->zoom + params->center_x;
	c.y = (min_y0 + py * (max_y0 - min_y0) / HEIGHT) /
		params->zoom + params->center_y;
	return (c);
}

int						move_cx_cy(t_scene *scene, int mouse_x,
						int mouse_y)
{
	int			i;
	t_complex	c;

	i = 0;
	c = scaled_xy((t_complex){0.0, 0.0}, scene->fractal_params[i],
		mouse_x, mouse_y);
	while (i < THREADS)
	{
		scene->fractal_params[i]->cx = c.x;
		scene->fractal_params[i]->cy = c.y;
		i++;
	}
	return (1);
}
