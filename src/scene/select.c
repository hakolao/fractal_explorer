/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   select.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 18:01:41 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/19 15:16:35 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Convenience selector for fractal specific parameters
*/

t_fractal_param_f			select_params(enum e_fractal type)
{
	return ((t_fractal_param_f[9]){
		mandelbrot_params,
		julia_params,
		burning_ship_params,
		mandelbrot_n_params,
		julia_n_params,
		bird_of_prey_params,
		julia_mod_params,
		phoenix_mod_params,
		burning_julia_params
	}[type]);
}

/*
** Convenience selector for fractal algorithms ("Artist draws")
** Basically each fractal in this project is either julia
** or mandelbrot type.
*/

t_fractal_artist			artist_draw(enum e_fractal type)
{
	if (type == mandelbrot || type == burning_ship ||
		type == mandelbrot_n || type == bird_of_prey)
		return (draw_mandelbrot);
	return (draw_julia);
}
