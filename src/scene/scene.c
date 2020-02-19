/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:13:53 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/20 00:07:23 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int					scene_render_params(t_scene *scene,
							void *mlx, void *mlx_wdw)
{
	scene->mlx = mlx;
	scene->mlx_wdw = mlx_wdw;
	scene->pixel_bits = 32;
	scene->line_bytes = scene->screen_width * 4;
	scene->pixel_endian = TRUE;
	scene->redraw = TRUE;
	if (!(scene->screenshot = mlx_new_image(scene->mlx, scene->screen_width,
			scene->screen_height)) ||
		!(scene->screenshot_buf = mlx_get_data_addr(scene->screenshot,
			&scene->pixel_bits, &scene->line_bytes, &scene->pixel_endian)))
		return (FALSE);
	return (TRUE);
}

t_scene						*new_scene(void *mlx, enum e_fractal artist,
							int width, int height)
{
	t_scene		*scene;
	char		*name;

	if (!(name = artist_name(artist)) ||
		!(scene = (t_scene*)malloc(sizeof(*scene))))
		return (NULL);
	scene->screen_width = width;
	scene->screen_height = height;
	if (!(scene->mlx_wdw = mlx_new_window(mlx, width, height, name)) ||
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
	scene->stop_phoenix_mod = FALSE;
	if (!scene_colors(scene) ||
		!(scene->fractal_params = thread_fractal_params(scene)))
		return (NULL);
	ft_strdel(&name);
	return (scene);
}

void						delete_scene(t_scene *scene)
{
	int		i;
	int		j;

	mlx_destroy_image(scene->mlx, scene->screenshot);
	i = -1;
	while (++i < 6)
		free(scene->colors[i]);
	free(scene->colors);
	i = -1;
	while (++i < THREADS)
	{
		free(scene->fractal_params[i]->pixel_bounds);
		free(scene->fractal_params[i]->color_palette);
		j = -1;
		while (++j < scene->fractal_params[i]->size)
			free(scene->fractal_params[i]->pixels[j]);
		free(scene->fractal_params[i]->pixels);
		mlx_destroy_image(scene->mlx, scene->fractal_params[i]->frame);
		free(scene->fractal_params[i]);
	}
	free(scene->fractal_params);
	free(scene);
}

t_scene						*image_render_scene(t_scene *scene)
{
	t_scene		*tmp_scene;
	int			i;

	if (!(tmp_scene = new_scene(scene->mlx, scene->artist, IMG_WIDTH,
		IMG_HEIGHT)) && log_err("Failed to create scene.", strerror(5)))
		return (NULL);
	mlx_destroy_window(tmp_scene->mlx, tmp_scene->mlx_wdw);
	i = -1;
	while (++i < 6)
	{
		tmp_scene->colors[i]->r = scene->colors[i]->r;
		tmp_scene->colors[i]->g = scene->colors[i]->g;
		tmp_scene->colors[i]->b = scene->colors[i]->b;
	}
	change_palette_size(tmp_scene, scene->palette_size -
		tmp_scene->palette_size);
	copy_scene_fractal_positions(tmp_scene->fractal_params,
		scene->fractal_params);
	return (tmp_scene);
}
