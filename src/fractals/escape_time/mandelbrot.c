/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:34:24 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/20 23:57:49 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int			out_circle(long double center_x,
					long double center_y, long double r,
					long double x, long double y)
{
	x -= center_x;
	y -= center_y;
	if (x * x + y * y > r * r)
		return(TRUE);
	return(FALSE);
}

/*
** https://en.wikipedia.org/wiki/Plotting_
** algorithms_for_the_Mandelbrot_set
** Having added complex functionality this could
** be also written:
** while (z.r * z.r + z.i * z.i) < 16 && iter < max_iter
** 		z  = c_add(c_pow(z, 2), c);
** Note that 16 is better for colors although 2 would be
** enough.
*/

long double			mandelbrot_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params)
{
	long double				iter;

	iter = 0.0;
	if (!(out_circle(-0.11, 0.0, 0.63, c.r, c.i) || c.r > 0.1)
		&& out_circle(-1.0, 0.0, 0.25, c.r, c.i)
		&& out_circle(-0.125, 0.744, 0.092, c.r, c.i)
		&& out_circle(-1.308, 0.0, 0.058, c.r, c.i)
		&& out_circle(0.0, 0.25, 0.35, c.r, c.i))
		return (iter);
	while (squares->r + squares->i <= 16 && iter < params->max_iter)
	{
		z.i = 2 * (z.i * z.r) + c.i;
		z.r = squares->r - squares->i + c.r;
		squares->r = z.r * z.r;
		squares->i = z.i * z.i;
		iter++;
	}
	return (iter);
}
