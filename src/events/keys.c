/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:22:18 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/11 15:41:27 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		randomize_palette(t_scene *scene)
{
	int		i;
	t_rgb	*colors;

	colors = (t_rgb[6]){
			{rand() % 255, 0, 0}, {rand() % 255, rand() % 255, 0},
			{0, rand() % 255, 0}, {0, rand() % 255, rand() % 255},
			{0, 0, rand() % 255}, {rand() % 255, 0, rand() % 255}};
	i = -1;
	while (++i < 6)
	{
		scene->colors[i]->r = colors[i].r;
		scene->colors[i]->g = colors[i].g;
		scene->colors[i]->b = colors[i].b;
	}
	i = -1;
	while (++i < THREADS)
	{
		free(scene->fractal_params[i]->color_palette);
		if (!color_palette(scene->fractal_params[i], scene->colors, 6,
			scene->palette_size))
			return (FALSE);
	}
	return (0);
}

static int		change_palette_size(t_scene *scene, int amount)
{
	int		i;

	if (scene->palette_size == 12 && amount < 0)
		return (FALSE);
	scene->palette_size += amount;
	i = 0;
	while (i < THREADS)
	{
		free(scene->fractal_params[i]->color_palette);
		if (!color_palette(scene->fractal_params[i], scene->colors, 6,
			scene->palette_size))
			return (FALSE);
		i++;
	}
	return (0);
}

int				handle_key_press(int key, void *param)
{
	t_scene		*scene;
	int			ret;

	scene = (t_scene *)param;
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_G)
		scene->show_guide = !scene->show_guide;
	if (key == KEY_C)
		randomize_palette(scene);
	ret = (key == KEY_W && zoom(scene, 1)) ||
			(key == KEY_S && zoom(scene, -1)) ||
			(key == KEY_2 && change_iters(scene, 1)) ||
			(key == KEY_1 && change_iters(scene, -1)) ||
			(key == KEY_LEFT && change_palette_size(scene, -1)) ||
			(key == KEY_RIGHT && change_palette_size(scene, 1));
	scene->redraw = TRUE;
	return (ret);
}

int				handle_key_release(int key, void *param)
{
	t_scene		*scene;

	scene = (t_scene *)param;
	(void)key;
	return (0);
}
