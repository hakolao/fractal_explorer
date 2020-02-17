/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:10:13 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/17 13:59:30 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** https://en.wikipedia.org/wiki/Plotting_
** algorithms_for_the_Mandelbrot_set
*/

double				mandelbrot_escape(t_complex z, t_complex c,
					t_complex *powers, t_fractal_params *params)
{
	long double				z_sqr;
	long double				iter;

	iter = 0.0;
	while (powers->x + powers->y <= 16 && iter < params->max_iter)
	{
		z.x = powers->x - powers->y + c.x;
		z.y = z_sqr - powers->x - powers->y + c.y;
		powers->x = z.x * z.x;
		powers->y = z.y * z.y;
		z_sqr = (z.x + z.y) * (z.x + z.y);
		iter++;
	}
	return (iter);
}

/*
** https://en.wikipedia.org/wiki/Multibrot_set
*/

double				multibrot_escape(t_complex z, t_complex c,
					t_complex *powers, t_fractal_params *params)
{
	long double				iter;
	long double				xtemp;

	iter = 0.0;
	z = c;
	while (z.x * z.x + z.y * z.y <= 16 && iter < params->max_iter)
	{
		xtemp = powl(z.x * z.x + z.y * z.y, (params->pow_n / 2.0)) *
			cos(params->pow_n * atan2(z.y, z.x)) + c.x;
		z.y = powl(z.x * z.x + z.y * z.y, (params->pow_n / 2.0)) *
			sin(params->pow_n * atan2(z.y, z.x)) + c.y;
		z.x = xtemp;
		iter++;
	}
	powers->x = powl(z.x, params->pow_n);
	powers->y = powl(z.y, params->pow_n);
	return (iter);
}

/*
** https://en.wikipedia.org/wiki/Julia_set
*/

double				julia_escape(t_complex z, t_complex c,
					t_complex *powers, t_fractal_params *params)
{
	long double				iter;

	iter = 0.0;
	while (powers->x + powers->y <=
		params->r * params->r && iter < params->max_iter)
	{
		z.y = 2 * (z.y * z.x) + c.y;
		z.x = powers->x - powers->y - c.x;
		powers->x = z.x * z.x;
		powers->y = z.y * z.y;
		iter++;
	}
	return (iter);
}

/*
** https://en.wikipedia.org/wiki/Julia_set
*/

double				julia_n_escape(t_complex z, t_complex c,
					t_complex *powers, t_fractal_params *params)
{
	long double				iter;
	long double				xtemp;

	iter = 0.0;
	while (z.x * z.x + z.y * z.y <=
		params->r * params->r && iter < params->max_iter)
	{
		xtemp = powl(z.x * z.x + z.y * z.y, (params->pow_n / 2.0)) *
			cos(params->pow_n * atan2(z.y, z.x)) + c.x;
		z.y = powl(z.x * z.x + z.y * z.y, (params->pow_n / 2.0)) *
			sin(params->pow_n * atan2(z.y, z.x)) + c.y;
		z.x = xtemp;
		iter++;
	}
	powers->x = z.x * z.x;
	powers->y = z.y * z.y;
	return (iter);
}

/*
** Modified version of julia set with abs values &
** flippable cx, cy signs :). Creates quite fancy
** fractals. Similar to burning ship julia
** http://usefuljs.net/fractals/docs/mandelvariants.html
*/

double				julia_mod_escape(t_complex z, t_complex c,
					t_complex *powers, t_fractal_params *params)
{
	long double				iter;

	iter = 0.0;
	while (powers->x + powers->y <=
		params->r * params->r && iter < params->max_iter)
	{
		z.y = 2 * ft_abs_long_double(z.y * z.x) +
			params->cx_sign * c.y;
		z.x = ft_abs_long_double(powers->x - powers->y) +
			params->cy_sign * c.x;
		powers->x = z.x * z.x;
		powers->y = z.y * z.y;
		iter++;
	}
	return (iter);
}
