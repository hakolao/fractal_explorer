/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:34:24 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/20 15:49:30 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** https://en.wikipedia.org/wiki/Burning_Ship_fractal
*/

long double			burning_ship_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params)
{
	long double				iter;

	iter = 0.0;
	while (squares->r + squares->i <= 16 && iter < params->max_iter)
	{
		z.i = ft_abs_long_double(2 * (z.i * z.r) + c.i);
		z.r = ft_abs_long_double(squares->r - squares->i + c.r);
		squares->r = z.r * z.r;
		squares->i = z.i * z.i;
		iter++;
	}
	return (iter);
}
