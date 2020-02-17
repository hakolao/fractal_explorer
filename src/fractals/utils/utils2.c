/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 23:23:33 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/13 23:53:16 by ohakola          ###   ########.fr       */
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

void			color_mandelbrot_pixel(t_pixel *pixel, long double iter,
				t_complex squares, t_fractal_params *params)
{
	iter = iter + 1.0 - log(log(squares.x + squares.y) /
		2.0 / log(2.0)) / log(2.0);
	pixel->color = lerp_rgb(params->color_palette[
			(int)floor(iter) % params->palette_size],
		params->color_palette[
			(int)((floor(iter)) + 1) % params->palette_size],
		iter - floor(iter));
}

void			color_julia_pixel(t_pixel *pixel, long double iter,
				t_complex squares, t_fractal_params *params)
{
	iter = iter + 2.0 - log(log(squares.x + squares.y)) / log(2.0);
	pixel->color = lerp_rgb(params->color_palette[
			(int)floor(iter) % params->palette_size],
		params->color_palette[
			(int)((floor(iter)) + 1) % params->palette_size],
		iter - floor(iter));
}

void			color_mandelbrot_n_pixel(t_pixel *pixel, long double iter,
				t_complex powers, t_fractal_params *params)
{
	if ((int)params->pow_n == 2)
	{
		color_mandelbrot_pixel(pixel, iter, powers, params);
		return ;
	}
	pixel->color = params->color_palette[(int)iter];
}

void			color_julia_n_pixel(t_pixel *pixel, long double iter,
				t_complex powers, t_fractal_params *params)
{
	if ((int)params->pow_n == 2)
	{
		color_julia_pixel(pixel, iter, powers, params);
		return ;
	}
	pixel->color = params->color_palette[(int)iter];
}
