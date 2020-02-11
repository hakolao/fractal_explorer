/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:22:18 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/11 12:23:01 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				randomize_palette(t_scene *scene)
{
	int		i;
	t_rgb	*colors;

	colors = (t_rgb[6]){
			{rand() % 255, 0, 0}, {rand() % 255, rand() % 255, 0},
			{0, rand() % 255, 0}, {0, rand() % 255, rand() % 255},
			{0, 0, rand() % 255}, {rand() % 255, 0, rand() % 255}};
	i = 0;
	while (i < THREADS)
	{
		free(scene->fractal_params[i]->color_palette);
		if (!color_palette(scene->fractal_params[i], colors, 6))
			return (FALSE);
		i++;
	}
	return (0);
}

int				handle_key_press(int key, void *param)
{
	t_scene		*scene;

	scene = (t_scene *)param;
	scene->redraw = TRUE;
	if (key == KEY_ESC)
		exit(0);
	if (key == KEY_G)
		scene->show_guide = !scene->show_guide;
	if (key == KEY_C)
		randomize_palette(scene);
	return ((key == KEY_W && zoom(scene, 1)) ||
			(key == KEY_S && zoom(scene, -1)) ||
			(key == KEY_2 && change_iters(scene, 1)) ||
			(key == KEY_1 && change_iters(scene, -1)));
}

int				handle_key_release(int key, void *param)
{
	t_scene		*scene;

	scene = (t_scene *)param;
	(void)key;
	return (0);
}
