/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:59:45 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/11 17:35:29 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				init_fractol(int *fractals, int size)
{
	t_scene		*scene;
	int			i;
	void		*mlx;
	void		*mlx_wdw;


	i = 0;
	while (i < size)
	{
		if (((mlx = mlx_init()) == NULL ||
			(mlx_wdw = mlx_new_window(mlx, WIDTH, HEIGHT,
			"Fractol - ohakola")) == NULL ||
			(scene = new_scene(mlx, mlx_wdw, fractals[i])) == NULL) &&
				log_err("Failed to create scene.", strerror(5)))
			return (0);
		mlx_hook(mlx_wdw, 2, 0, handle_key_press, scene);
		mlx_hook(mlx_wdw, 3, 0, handle_key_release, scene);
		mlx_hook(mlx_wdw, 4, 0, handle_mouse_button_press, scene);
		mlx_hook(mlx_wdw, 5, 0, handle_mouse_button_release, scene);
		mlx_hook(mlx_wdw, 6, 0, handle_mouse_move, scene);
		mlx_hook(mlx_wdw, 17, 0, handle_exit_event, scene);
		mlx_loop_hook(mlx, handle_loop, scene);
		i++;
	}
	mlx_loop(mlx);
	return (0);
}

int				parse_args(int argc, char **argv)
{
	int	i;
	int	*fractals;
	int	size;

	fractals = (int[2]){mandelbrot, julia};
	i = -1;
	size = 0;
	while (++i < 2 && i < argc - 1)
	{
		if (ft_strequ(argv[i + 1], "mandelbrot"))
		{
			size++;
			fractals[i] = mandelbrot;
		}
		else if (ft_strequ(argv[i + 1], "julia"))
		{
			size++;
			fractals[i] = julia;
		}
		else
			return (log_guide() && FALSE);
	}
	return (init_fractol(fractals, size));
}

int				main(int argc, char **argv)
{
	if (argc > 1)
		parse_args(argc, argv);
	else
		init_fractol(&(int){mandelbrot}, 1);
	return (0);
}
