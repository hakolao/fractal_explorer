/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:21:55 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/20 19:22:01 by ohakola          ###   ########.fr       */
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
	ft_putstr("FRACTOL\n"
			"-----------\n"
			"Press key G for guide on screen.\n"
			"Press Esc to exit\n\n"
			"Allowed arguments:\n\nall\n"
			"mandelbrot (Default)\njulia"
			"\nburning_ship\nmandelbrot_n\njulia_n\nbird_of_prey"
			"\njulia_mod\nphoenix_mod\nburning_julia\n"
			"-colors=255,22,22\\|20,20,33\n\n"
			"Colors: RGBs (as many as you'd like) split by '|'"
			" and numbers between "
			"0 and 255. Backslash must be escaped\n"
			"Example: ./fractol mandelbrot julia "
			"-colors=255,0,0\\|0,255,0\\|0,0,255");
	return (1);
}
