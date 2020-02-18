/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 23:39:18 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/18 13:40:15 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				is_valid_arg(char *arg)
{
	return (ft_strequ(arg, "mandelbrot") ||
			ft_strequ(arg, "julia") ||
			ft_strequ(arg, "burning_ship") ||
			ft_strequ(arg, "bird_of_prey") ||
			ft_strequ(arg, "julia_n") ||
			ft_strequ(arg, "julia_mod") ||
			ft_strequ(arg, "phoenix") ||
			ft_strequ(arg, "nova") ||
			ft_strequ(arg, "burning_julia") ||
			ft_strequ(arg, "mandelbrot_n"));
}

int				check_args(char *arg, int *size, int *fractal)
{
	int		res;

	if ((res = is_valid_arg(arg)))
		(*size)++;
	if (ft_strequ(arg, "mandelbrot"))
		*fractal = mandelbrot;
	else if (ft_strequ(arg, "julia"))
		*fractal = julia;
	else if (ft_strequ(arg, "burning_ship"))
		*fractal = burning_ship;
	else if (ft_strequ(arg, "mandelbrot_n"))
		*fractal = mandelbrot_n;
	else if (ft_strequ(arg, "julia_n"))
		*fractal = julia_n;
	else if (ft_strequ(arg, "bird_of_prey"))
		*fractal = bird_of_prey;
	else if (ft_strequ(arg, "julia_mod"))
		*fractal = julia_mod;
	else if (ft_strequ(arg, "phoenix"))
		*fractal = phoenix;
	else if (ft_strequ(arg, "burning_julia"))
		*fractal = burning_julia;
	else if (ft_strequ(arg, "nova"))
		*fractal = nova;
	return (res);
}
