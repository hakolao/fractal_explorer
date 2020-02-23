/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:21:55 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/23 16:27:38 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				log_err(char *str, char *strerror)
{
	ft_putstr("\033[0;31m");
	ft_putstr_fd(strerror, 2);
	ft_putstr_fd(": ", 2);
	ft_putendl_fd(str, 2);
	ft_putstr("\033[0m");
	return (1);
}

int				log_perr(char *str)
{
	ft_putstr("\033[0;31m");
	perror(str);
	ft_putstr("\033[0m");
	return (1);
}

int				log_guide(void)
{
	ft_putstr("-----------\nFRACTOL\n"
		"-----------\n"
		"usage:\n ./fractol [fractal_name] [-colors=[r,g,b\\|r,g,b\\|+]\n\n"
		"fractals:\n mandelbrot (Default)\n julia"
		"\n burning_ship\n mandelbrot_n\n julia_n\n bird_of_prey"
		"\n julia_mod\n phoenix_mod\n burning_julia\n\n"
		"example:\n ./fractol mandelbrot julia "
		"-colors=255,0,0\\|0,255,0\\|0,0,255\n\n"
		"more options:\n"
		" ESC to exit\n"
		" G for guide & further actions on screen.\n"
		"----------------------------------------\n");
	return (1);
}
