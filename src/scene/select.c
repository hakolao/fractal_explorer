/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:01:41 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/13 18:02:06 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
