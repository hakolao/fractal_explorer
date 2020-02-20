/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bird_of_prey.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 15:34:24 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/20 15:49:49 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
