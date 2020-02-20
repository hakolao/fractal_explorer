/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:21:55 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/20 15:57:32 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				log_err(char *str, char *strerror)
{
	ft_putstr_fd(strerror, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(str, 2);
	return (1);
}

int				log_perr(char *str)
{
	perror(str);
	return (1);
}

int				log_guide(void)
{
	ft_putstr("Default fractal: Mandelbrot\n"
			"Press key G for guide / info on screen.\n"
			"Allowed arguments: [all (for all available fractals),\n"
			"mandelbrot, julia, "
			"burning_ship, mandelbrot_n, julia_n, bird_of_prey, "
			"julia_mod, phoenix_mod, burning_julia]\n");
	return (1);
}
