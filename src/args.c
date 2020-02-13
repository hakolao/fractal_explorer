/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 23:39:18 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/13 23:41:41 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				check_args(char *arg, int *size, int *fractal)
{
	int		res;

	res = ft_strequ(arg, "mandelbrot") ||
			ft_strequ(arg, "julia") ||
			ft_strequ(arg, "burning_ship") ||
			ft_strequ(arg, "julia_n") ||
			ft_strequ(arg, "mandelbrot_n");
	if (res)
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
	return (res);
}
