/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:21:55 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/23 19:06:19 by ohakola          ###   ########.fr       */
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

void			print_mandelbrot_header(void)
{
	int					x;
	int					y;
	int					max_x;
	int					max_y;
	t_fractal_params	par;

	max_x = 80.0;
	max_y = 20.0;
	par = (t_fractal_params){.min_x = -2.0, .max_x = 2.0, .min_y = -2.0,
		.max_y = 2.0, .zoom = 1.0, .center_x = -0.7, .center_y = 0.0,
		.height = max_y, .width = max_x, .max_iter = 10};
	y = -1;
	while (++y < max_y)
	{
		x = -1;
		while (++x < max_x)
			ft_putchar((char[3]){'.', ',', ' '}[
				(int)mandelbrot_escape((t_complex){0.0, 0.0},
					(t_complex){(par.min_x + x * (par.max_x - par.min_x)
					/ par.width) / par.zoom + par.center_x,
					(par.min_y + y * (par.max_y - par.min_y) /
						par.height) / par.zoom + par.center_y},
					&(t_complex){0.0, 0.0}, &par) % 3]);
		ft_putstr("\n");
	}
}

int				log_guide(void)
{
	ft_putstr(
	"------------------------------------------------------------"
	"--------------------\n"
	"#######                                          \n"
	"#       #####    ##    ####  #####  ####  #      \n"
	"#       #    #  #  #  #    #   #   #    # #      \n"
	"#####   #    # #    # #        #   #    # #      \n"
	"#       #####  ###### #        #   #    # #      \n"
	"#       #   #  #    # #    #   #   #    # #      \n"
	"#       #    # #    #  ####    #    ####  ######\n"
	"------------------------------------------------------------"
	"--------------------\n");
	print_mandelbrot_header();
	ft_putstr("usage:\n ./fractol [fractal_name] [-colors=[r,g,b\\|r,g,b\\|+]"
	"\n\nfractals:\n all (opens all)\n mandelbrot (Default)\n julia"
	"\n burning_ship\n mandelbrot_n\n julia_n\n bird_of_prey"
	"\n julia_mod\n phoenix_mod\n burning_julia\n\n"
	"example:\n ./fractol mandelbrot julia "
	"-colors=255,0,0\\|0,255,0\\|0,0,255\n\n"
	"more options:\n"
	" ESC to exit\n"
	" G for guide & further actions on screen.\n"
	"------------------------------------------------------------"
	"--------------------\n");
	return (1);
}
