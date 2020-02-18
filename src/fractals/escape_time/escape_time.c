/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:10:13 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/18 18:17:26 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** https://en.wikipedia.org/wiki/Plotting_
** algorithms_for_the_Mandelbrot_set
** Having added complex functionality this could
** be also written:
** while (z.r * z.r + z.i * z.i) < 16 && iter < max_iter
** 		z  = c_add(c_pow(z, 2), c);
*/

double				mandelbrot_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params)
{
	long double				z_sqr;
	long double				iter;

	iter = 0.0;
	while (squares->r + squares->i <= 16 && iter < params->max_iter)
	{
		z.r = squares->r - squares->i + c.r;
		z.i = z_sqr - squares->r - squares->i + c.i;
		squares->r = z.r * z.r;
		squares->i = z.i * z.i;
		z_sqr = (z.r + z.i) * (z.r + z.i);
		iter++;
	}
	return (iter);
}

/*
** https://en.wikipedia.org/wiki/Multibrot_set
*/

double				multibrot_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params)
{
	long double				iter;
	long double				xtemp;

	iter = 0.0;
	z = c;
	while (z.r * z.r + z.i * z.i <= 16 && iter < params->max_iter)
	{
		xtemp = powl(z.r * z.r + z.i * z.i, (params->pow_n / 2.0)) *
			cos(params->pow_n * atan2(z.i, z.r)) + c.r;
		z.i = powl(z.r * z.r + z.i * z.i, (params->pow_n / 2.0)) *
			sin(params->pow_n * atan2(z.i, z.r)) + c.i;
		z.r = xtemp;
		iter++;
	}
	squares->r = z.r * z.r;
	squares->i = z.i * z.i;
	return (iter);
}

/*
** https://en.wikipedia.org/wiki/Julia_set
*/

double				julia_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params)
{
	long double				iter;

	iter = 0.0;
	while (squares->r + squares->i <=
		params->r * params->r && iter < params->max_iter)
	{
		z.i = 2 * (z.i * z.r) + c.i;
		z.r = squares->r - squares->i + c.r;
		squares->r = z.r * z.r;
		squares->i = z.i * z.i;
		iter++;
	}
	return (iter);
}

/*
** https://en.wikipedia.org/wiki/Julia_set
*/

double				julia_n_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params)
{
	long double				iter;
	long double				xtemp;

	iter = 0.0;
	while (z.r * z.r + z.i * z.i <=
		params->r * params->r && iter < params->max_iter)
	{
		xtemp = powl(z.r * z.r + z.i * z.i, (params->pow_n / 2.0)) *
			cos(params->pow_n * atan2(z.i, z.r)) + c.r;
		z.i = powl(z.r * z.r + z.i * z.i, (params->pow_n / 2.0)) *
			sin(params->pow_n * atan2(z.i, z.r)) + c.i;
		z.r = xtemp;
		iter++;
	}
	squares->r = z.r * z.r;
	squares->i = z.i * z.i;
	return (iter);
}

/*
** Modified version of julia set with abs values &
** flippable cx, cy signs (flipping doesn't do much
** just flips the axes) :). Creates quite fancy
** fractals. Similar to burning ship julia
** http://usefuljs.net/fractals/docs/mandelvariants.html
*/

double				julia_mod_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params)
{
	long double				iter;

	iter = 0.0;
	while (squares->r + squares->i <=
		params->r * params->r && iter < params->max_iter)
	{
		z.i = 2 * ft_abs_long_double(z.i * z.r) +
			params->cx_sign * c.i;
		z.r = ft_abs_long_double(squares->r - squares->i) +
			params->cy_sign * c.r;
		squares->r = z.r * z.r;
		squares->i = z.i * z.i;
		iter++;
	}
	return (iter);
}
