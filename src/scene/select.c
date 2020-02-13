/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:01:41 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/13 23:47:13 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Convenience selector for fractal specific parameters
*/

t_fractal_param_f			select_params(enum e_fractal type)
{
	return ((t_fractal_param_f[5]){
		mandelbrot_params,
		julia_params,
		burning_ship_params,
		mandelbrot_n_params,
		julia_n_params
	}[type]);
}

/*
** Convenience selector for fractal algorithms ("Artist draws")
*/

t_fractal_artist			artist_draw(enum e_fractal type)
{
	return ((t_fractal_artist[5]){
		draw_mandelbrot,
		draw_julia,
		draw_burning_ship,
		draw_mandelbrot_n,
		draw_julia_n
	}[type]);
}
