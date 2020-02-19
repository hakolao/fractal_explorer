/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phoenix_mod.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:34:24 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/19 15:39:57 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
