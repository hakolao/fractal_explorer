/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:13:53 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/25 14:31:17 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int					scene_render_params(t_scene *scene,
							void *mlx, void *mlx_wdw)
{
	int		i;

	scene->mlx = mlx;
	scene->mlx_wdw = mlx_wdw;
	scene->pixel_bits = 32;
	scene->line_bytes = scene->screen_width * 4;
	scene->pixel_endian = TRUE;
	scene->redraw = TRUE;
	if (!(scene->colors = malloc(sizeof(t_rgb*) * scene->colors_size)) ||
		!(scene->screenshot = mlx_new_image(scene->mlx, scene->screen_width,
			scene->screen_height)) ||
		!(scene->screenshot_buf = mlx_get_data_addr(scene->screenshot,
			&scene->pixel_bits, &scene->line_bytes, &scene->pixel_endian)))
		return (FALSE);
	i = -1;
	while (++i < scene->colors_size)
		if (!(scene->colors[i] = malloc(sizeof(t_rgb))) ||
			!(scene->colors[i] =
				ft_memcpy(scene->colors[i],
					scene->data->color_data->colors[i], sizeof(t_rgb))))
			return (FALSE);
	scene->ui_color = UI_COLOR;
	scene->toggle_zoom_center = TRUE;
	return (TRUE);
}

t_scene						*new_scene(t_scenes *data, enum e_fractal artist,
							int width, int height)
{
	t_scene		*scene;
	char		*name;

	if (!(name = artist_name(artist)) ||
		!(scene = (t_scene*)malloc(sizeof(*scene))))
		return (NULL);
	scene->screen_width = width;
	scene->screen_height = height;
	scene->data = data;
	scene->colors_size = data->color_data->size;
	if (!(scene->mlx_wdw = mlx_new_window(data->mlx, width, height, name)) ||
		!scene_render_params(scene, data->mlx, scene->mlx_wdw))
		return (NULL);
	scene->mlx = data->mlx;
	scene->mouse_left_pressed = FALSE;
	scene->show_guide = FALSE;
	scene->palette_size = COLORS;
	scene->artist = artist;
	scene->stop_julia = FALSE;
	scene->stop_phoenix_mod = FALSE;
	if (!(scene->fractal_params = thread_fractal_params(scene)))
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
	while (++i < THREADS)
	{
		free(scene->fractal_params[i]->pixel_bounds);
		free(scene->fractal_params[i]->palette);
		j = -1;
		while (++j < scene->fractal_params[i]->size)
			free(scene->fractal_params[i]->pixels[j]);
		free(scene->fractal_params[i]->pixels);
		mlx_destroy_image(scene->mlx, scene->fractal_params[i]->frame);
		free(scene->fractal_params[i]);
	}
	i = -1;
	while (++i < scene->colors_size)
		free(scene->colors[i]);
	free(scene->colors);
	free(scene->fractal_params);
	free(scene);
	scene = NULL;
}

t_scene						*image_render_scene(t_scene *scene)
{
	t_scene		*tmp_scene;
	int			i;

	i = -1;
	while (++i < scene->colors_size)
	{
		scene->data->color_data->colors[i]->r = scene->colors[i]->r;
		scene->data->color_data->colors[i]->g = scene->colors[i]->g;
		scene->data->color_data->colors[i]->b = scene->colors[i]->b;
	}
	if (!(tmp_scene = new_scene(scene->data, scene->artist, IMG_WIDTH,
		IMG_HEIGHT)) && log_err("Failed to create scene.", strerror(5)))
		return (NULL);
	mlx_destroy_window(tmp_scene->mlx, tmp_scene->mlx_wdw);
	change_palette_size(tmp_scene, scene->palette_size -
		tmp_scene->palette_size);
	copy_scene_fractal_positions(tmp_scene->fractal_params,
		scene->fractal_params);
	return (tmp_scene);
}
