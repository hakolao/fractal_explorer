/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_mod.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:34:24 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/19 15:39:06 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Modified version of julia set with abs values &
** flippable cx, cy signs (flipping doesn't do much
** just flips the axes) :). Creates quite fancy
** fractals. Similar to burning ship julia
** http://usefuljs.net/fractals/docs/mandelvariants.html
*/

long double			julia_mod_escape(t_complex z, t_complex c,
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
