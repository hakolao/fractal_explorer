/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_n.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:35:31 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/19 15:38:23 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** https://en.wikipedia.org/wiki/Julia_set
*/

long double			julia_n_escape(t_complex z, t_complex c,
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
