/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:59:45 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/13 16:47:15 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_scene			*mlx_init_scene(void *mlx, t_scene *scene,
				int scene_id, enum e_fractal artist)
{
	if (!(scene = new_scene(mlx, artist)) &&
			log_err("Failed to create scene.", strerror(5)))
		return (NULL);
	scene->id = scene_id;
	mlx_hook(scene->mlx_wdw, 2, 0, handle_key_press, scene);
	mlx_hook(scene->mlx_wdw, 3, 0, handle_key_release, scene);
	mlx_hook(scene->mlx_wdw, 4, 0, handle_mouse_button_press, scene);
	mlx_hook(scene->mlx_wdw, 5, 0, handle_mouse_button_release, scene);
	mlx_hook(scene->mlx_wdw, 6, 0, handle_mouse_move, scene);
	mlx_hook(scene->mlx_wdw, 17, 0, handle_exit_event, scene);
	return (scene);
}

int				init_fractol(int *fractals, int size)
{
	t_scenes	*data;
	int			i;

	if (!(data = malloc(sizeof(*data))) ||
		!(data->scenes = malloc(sizeof(*data->scenes) * size)) ||
		!(data->mlx = mlx_init()))
		return (FALSE);
	data->size = size;
	i = -1;
	while (++i < size)
		if (!(data->scenes[i] =
				mlx_init_scene(data->mlx, data->scenes[i], i, fractals[i])))
			return (FALSE);
	mlx_loop_hook(data->mlx, handle_loop, data);
	mlx_loop(data->mlx);
	return (FALSE);
}

int				is_valid_arg(char *arg, int *size)
{
	int		res;

	res = ft_strequ(arg, "mandelbrot") ||
			ft_strequ(arg, "julia") ||
			ft_strequ(arg, "burning_ship") ||
			ft_strequ(arg, "mandelbrot_n");
	if (res)
		(*size)++;
	return (res);
}

int				parse_args(int argc, char **argv)
{
	int	i;
	int	fractals[argc - 1];
	int	size;

	i = -1;
	size = 0;
	while (++i < argc - 1)
	{
		fractals[i] = -1;
		if (!is_valid_arg(argv[i + 1], &size))
			return (log_guide() && FALSE);
		if (ft_strequ(argv[i + 1], "mandelbrot"))
			fractals[i] = mandelbrot;
		else if (ft_strequ(argv[i + 1], "julia"))
			fractals[i] = julia;
		else if (ft_strequ(argv[i + 1], "burning_ship"))
			fractals[i] = burning_ship;
		else if (ft_strequ(argv[i + 1], "mandelbrot_n"))
			fractals[i] = mandelbrot_n;
	}
	if (size > MAX_WINDOWS)
		return (log_err("Too many windows: max 10", strerror(5)));
	ft_sort_int_tab(fractals, argc - 1, -1);
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
