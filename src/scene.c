/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:13:53 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/12 17:02:02 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int					scene_render_params(t_scene *scene,
							void *mlx, void *mlx_wdw)
{
	scene->mlx = mlx;
	scene->mlx_wdw = mlx_wdw;
	scene->pixel_bits = 32;
	scene->line_bytes = WIDTH * 4;
	scene->pixel_endian = TRUE;
	scene->redraw = TRUE;
	return (TRUE);
}

static t_fractal_param_f	select_params(enum e_fractal type)
{
	return ((t_fractal_param_f[2]){
		mandelbrot_params,
		julia_params
	}[type]);
}

static t_fractal_params		**thread_fractal_params(t_scene *scene)
{
	t_fractal_params		**fractal_params;
	int						i;

	if (!(fractal_params = malloc(sizeof(*fractal_params) * THREADS)) ||
		(HEIGHT % THREADS != 0 && log_err("HEIGHT % THREADS != 0", "Headers")))
		return (NULL);
	i = 0;
	while (i < THREADS)
	{
		if (!(fractal_params[i] =
				malloc(sizeof(**fractal_params) * PIXELS)) ||
			!select_params(scene->artist)(fractal_params[i], scene, i))
			return (NULL);
		i++;
	}
	return (fractal_params);
}

static char					*artist_name(enum e_fractal artist)
{
	char	*name;

	if (artist == mandelbrot)
		name = ft_strdup("Mandelbrot");
	else if (artist == julia)
		name = ft_strdup("Julia");
	else
		name = ft_strdup("Fractol");
	return (name);
}

t_scene						*new_scene(void *mlx, enum e_fractal artist)
{
	t_scene		*scene;
	char		*name;

	if (!(name = artist_name(artist)) ||
		!(scene = (t_scene*)malloc(sizeof(*scene))) ||
		!(scene->mlx_wdw = mlx_new_window(mlx, WIDTH, HEIGHT, name)) ||
		!scene_render_params(scene, mlx, scene->mlx_wdw))
		return (NULL);
	scene->mlx = mlx;
	scene->mouse_left_pressed = FALSE;
	scene->mouse_x = FALSE;
	scene->mouse_y = FALSE;
	scene->show_guide = FALSE;
	scene->palette_size = COLORS;
	scene->artist = artist;
	scene->stop_julia = FALSE;
	if (!scene_colors(scene) ||
		!(scene->fractal_params = thread_fractal_params(scene)))
		return (NULL);
	ft_strdel(&name);
	return (scene);
}
