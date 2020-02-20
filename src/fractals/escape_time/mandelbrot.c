/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:34:24 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/20 15:48:02 by ohakola          ###   ########.fr       */
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
** Note that 16 is better for colors although 2 would be
** enough.
*/

long double			mandelbrot_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params)
{
	long double				iter;

	iter = 0.0;
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
