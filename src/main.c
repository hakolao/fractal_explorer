/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:59:45 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/20 17:59:38 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		mlx_init_scene(t_scene *scene)
{
	mlx_hook(scene->mlx_wdw, 2, 0, handle_key_press, scene);
	mlx_hook(scene->mlx_wdw, 3, 0, handle_key_release, scene);
	mlx_hook(scene->mlx_wdw, 4, 0, handle_mouse_button_press, scene);
	mlx_hook(scene->mlx_wdw, 5, 0, handle_mouse_button_release, scene);
	mlx_hook(scene->mlx_wdw, 6, 0, handle_mouse_move, scene);
	mlx_hook(scene->mlx_wdw, 17, 0, handle_exit_event, scene);
}

/*
** Separates fractals into windows depending on input
** fractal array (see enum e_fractal) and its size
*/

int				init_fractol(int *artists, int size, t_colors *color_data)
{
	t_scenes	*data;
	int			i;

	if (!(data = malloc(sizeof(*data))) ||
		!(data->scenes = malloc(sizeof(*data->scenes) * size)) ||
		!(data->mlx = mlx_init()))
		return (FALSE);
	data->size = size;
	data->color_data = color_data;
	printf("%p\n", data->color_data);
	i = -1;
	while (++i < size)
	{
		if (!(data->scenes[i] =
				new_scene(data, artists[i], WIDTH, HEIGHT)) &&
			log_err("Failed to create scene.", strerror(5)))
			return (FALSE);
		data->scenes[i]->id = i;
		mlx_init_scene(data->scenes[i]);
	}
	mlx_loop_hook(data->mlx, handle_loop, data);
	mlx_loop(data->mlx);
	return (FALSE);
}

static t_colors	*get_colors(int argc, char **argv)
{
	int			i;
	int			color_i;
	int			has_colors;
	t_colors	*color_data;

	i = -1;
	has_colors = FALSE;
	while (++i < argc - 1)
	{
		if (ft_match(argv[i + 1], "-colors=*") && (color_i = i + 1))
		{
			has_colors = TRUE;
			break ;
		}
	}
	if (has_colors)
	{
		if (!(color_data = parse_colors(argv[color_i])) &&
			log_err("Defaulting back to default color palette", strerror(5)))
			if (!(color_data = default_colors()) &&
				log_err("Failed to create any colors", strerror(5)))
				return (NULL);
	}
	else if (!(color_data = default_colors()) &&
				log_err("Failed to create any colors", strerror(5)))
				return (NULL);
	return (color_data);
}

int				parse_args(int argc, char **argv)
{
	int			i;
	int			fractals[argc - 1];
	int			size;
	t_colors	*color_data;

	i = -1;
	size = 0;
	color_data = NULL;
	if (!(color_data = get_colors(argc, argv)))
		return (FALSE);
	if (argc <= 1)
		return (log_guide() && init_fractol((int[1]){mandelbrot}, 1, color_data));
	while (++i < argc - 1)
	{
		fractals[i] = -1;
		if (ft_strequ(argv[i + 1], "all"))
			return (init_fractol((int[9]){mandelbrot, julia, burning_ship,
				mandelbrot_n, julia_n, bird_of_prey, julia_mod,
				phoenix_mod, burning_julia}, 9, color_data));
		if (!check_args(argv[i + 1], &size, &fractals[i]))
			return (log_guide() && FALSE);
	}
	if (size > MAX_WINDOWS)
		return (log_err("Too many windows: max 10", strerror(5)));
	ft_sort_int_tab(fractals, argc - 1, -1);
	return (init_fractol(fractals, size, color_data));
}

int				main(int argc, char **argv)
{
	parse_args(argc, argv);
	return (0);
}
