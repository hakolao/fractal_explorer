/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:59:45 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/12 16:32:48 by ohakola          ###   ########.fr       */
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
