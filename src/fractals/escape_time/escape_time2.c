/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_time2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:19:35 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/19 15:12:43 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** https://en.wikipedia.org/wiki/Burning_Ship_fractal
*/

long double			burning_ship_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params)
{
	long double				z_sqr;
	long double				iter;

	iter = 0.0;
	while (squares->r + squares->i <= 16 && iter < params->max_iter)
	{
		z.r = ft_abs_long_double(squares->r - squares->i + c.r);
		z.i = ft_abs_long_double(z_sqr - squares->r - squares->i + c.i);
		squares->r = z.r * z.r;
		squares->i = z.i * z.i;
		z_sqr = (z.r + z.i) * (z.r + z.i);
		iter++;
	}
	return (iter);
}

/*
** https://www.app13x.com/MacShipTrek.html
*/

long double			bird_of_prey_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params)
{
	long double				iter;

	iter = 0.0;
	while (squares->r + squares->i <= 16 && iter < params->max_iter)
	{
		z.r = (squares->r - squares->i * 3) *
			ft_abs_long_double(z.r) + c.r;
		z.i = (squares->r * 3 - squares->i) *
			ft_abs_long_double(z.i) + c.i;
		squares->r = z.r * z.r;
		squares->i = z.i * z.i;
		iter++;
	}
	return (iter);
}

/*
** This does not quite look like the phoenixes online
** but I am unsure what's wrong with the iteration parameters...
** Nevertheless it's pretty.
*/

long double			phoenix_mod_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params)
{
	long double				iter;
	long double				xold;
	long double				yold;
	long double				xtemp;
	long double				ytemp;

	iter = 0.0;
	xold = 0.0;
	yold = 0.0;
	while (z.r * z.r + z.i * z.i <=
		params->r * params->r && iter < params->max_iter)
	{
		xtemp = z.r * z.r - z.i * z.i + c.r + params->px *
			xold - params->py * yold;
		ytemp = 2 * z.i * z.r - c.i + params->px * yold + params->py * xold;
		xold = z.r;
		yold = z.i;
		z.r = xtemp;
		z.i = ytemp;
		squares->r = z.r * z.r;
		squares->i = z.i * z.i;
		iter++;
	}
	return (iter);
}

/*
** http://usefuljs.net/fractals/docs/mandelvariants.html
*/

long double			burning_julia_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params)
{
	long double				iter;

	iter = 0.0;
	while (squares->r + squares->i <=
		params->r * params->r && iter < params->max_iter)
	{
		z.i = ft_abs_long_double(2 * (z.i * z.r) + c.i);
		z.r = ft_abs_long_double(squares->r - squares->i - c.r);
		squares->r = z.r * z.r;
		squares->i = z.i * z.i;
		iter++;
	}
	return (iter);
}
