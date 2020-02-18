/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 23:23:33 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/18 18:10:07 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				increment_pow_n(t_scene *scene, int incr)
{
	int			i;

	if (!(scene->artist == mandelbrot_n ||
			scene->artist == julia_n))
		return (0);
	i = 0;
	while (i < THREADS)
	{
		scene->fractal_params[i]->pow_n += incr;
		if (scene->fractal_params[i]->pow_n <= 2)
			scene->fractal_params[i]->pow_n = 2;
		else if (scene->fractal_params[i]->pow_n >= 100)
			scene->fractal_params[i]->pow_n = 100;
		i++;
	}
	return (0);
}

/*
** https://linas.org/art-gallery/escape/smooth.html
*/

void			smooth_color_pixel(t_pixel *pixel, long double iter,
				t_complex squares, t_fractal_params *params)
{
	iter = iter + 1.0 - log(log(squares.r + squares.i)) / log(params->pow_n);
	pixel->color = lerp_rgb(params->color_palette[
			(int)floor(iter) % params->palette_size],
		params->color_palette[
			(int)((floor(iter)) + 1) % params->palette_size],
		iter - floor(iter));
}

int				flip_cx_sign(t_scene *scene)
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

int				flip_cy_sign(t_scene *scene)
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

int				move_px_py(t_scene *scene, int mouse_x,
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
