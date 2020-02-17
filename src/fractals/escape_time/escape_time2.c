/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   escape_time2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 13:19:35 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/17 14:09:18 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** https://en.wikipedia.org/wiki/Burning_Ship_fractal
*/

double				burning_ship_escape(t_complex z, t_complex c,
					t_complex *powers, t_fractal_params *params)
{
	long double				z_sqr;
	long double				iter;

	iter = 0.0;
	while (powers->x + powers->y <= 16 && iter < params->max_iter)
	{
		z.x = ft_abs_long_double(powers->x - powers->y + c.x);
		z.y = ft_abs_long_double(z_sqr - powers->x - powers->y + c.y);
		powers->x = z.x * z.x;
		powers->y = z.y * z.y;
		z_sqr = (z.x + z.y) * (z.x + z.y);
		iter++;
	}
	return (iter);
}

/*
** https://www.app13x.com/MacShipTrek.html
*/

double				bird_of_prey_escape(t_complex z, t_complex c,
					t_complex *powers, t_fractal_params *params)
{
	long double				iter;

	iter = 0.0;
	while (powers->x + powers->y <= 16 && iter < params->max_iter)
	{
		z.x = (powers->x - powers->y * 3) *
			ft_abs_long_double(z.x) + c.x;
		z.y = (powers->x * 3 - powers->y) *
			ft_abs_long_double(z.y) + c.y;
		powers->x = z.x * z.x;
		powers->y = z.y * z.y;
		iter++;
	}
	return (iter);
}

double				phoenix_escape(t_complex z, t_complex c,
					t_complex *powers, t_fractal_params *params)
{
	long double				iter;
	long double				xold;
	long double				yold;
	long double				xtemp;
	long double				ytemp;

	xold = 1.0;
	yold = 0.0;
	iter = 0.0;
	while (z.x * z.x + z.y * z.y <=
		params->r * params->r && iter < params->max_iter)
	{
		ytemp = 2 * z.y * z.x + c.y + yold * c.y;
		xtemp = z.x * z.x - z.y * z.y + c.x + xold * c.x;
		xold = z.x;
		yold = z.y;
		z.x = xtemp;
		z.y = ytemp;
		powers->x = z.x * z.x;
		powers->y = z.y * z.y;
		iter++;
	}
	return (iter);
}

/*
** http://usefuljs.net/fractals/docs/mandelvariants.html
*/

double				burning_julia_escape(t_complex z, t_complex c,
					t_complex *powers, t_fractal_params *params)
{
	long double				iter;

	iter = 0.0;
	while (powers->x + powers->y <=
		params->r * params->r && iter < params->max_iter)
	{
		z.y = ft_abs_long_double(2 * (z.y * z.x) + c.y);
		z.x = ft_abs_long_double(powers->x - powers->y - c.x);
		powers->x = z.x * z.x;
		powers->y = z.y * z.y;
		iter++;
	}
	return (iter);
}