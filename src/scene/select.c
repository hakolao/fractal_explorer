/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:01:41 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/14 13:51:03 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Convenience selector for fractal specific parameters
*/

t_fractal_param_f			select_params(enum e_fractal type)
{
	return ((t_fractal_param_f[7]){
		mandelbrot_params,
		julia_params,
		burning_ship_params,
		mandelbrot_n_params,
		julia_n_params,
		bird_of_prey_params,
		phoenix_params
	}[type]);
}

/*
** Convenience selector for fractal algorithms ("Artist draws")
*/

t_fractal_artist			artist_draw(enum e_fractal type)
{
	return ((t_fractal_artist[7]){
		draw_mandelbrot,
		draw_julia,
		draw_burning_ship,
		draw_mandelbrot_n,
		draw_julia_n,
		draw_bird_of_prey,
		draw_phoenix
	}[type]);
}
