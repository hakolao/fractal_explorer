/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:29:37 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/19 15:31:38 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Zoom in the fractal. This also increments iteration count
** Starting from lower iterations is initially more performant
*/

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
		scene->fractal_params[i]->center_x = new.r;
		scene->fractal_params[i]->center_y = new.i;
		i++;
	}
	return (0);
}

/*
** Change julia type fractal param c based on mouse position
*/

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
		scene->fractal_params[i]->cx = c.r;
		scene->fractal_params[i]->cy = c.i;
		i++;
	}
	return (1);
}

/*
** Change phoenix fractal's param p based on mouse position
*/

int						move_px_py(t_scene *scene, int mouse_x,
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
