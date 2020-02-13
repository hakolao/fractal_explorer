/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:22:18 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/13 16:34:08 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				increment_pow_n(t_scene *scene, int incr)
{
	int			i;

	i = 0;
	while (i < THREADS)
	{
		scene->fractal_params[i]->pow_n += incr;
		i++;
	}
	return (1);
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
	ret = (key == KEY_W && zoom(scene, 1.03)) ||
			(key == KEY_S && zoom(scene, 1 / 1.03)) ||
			(key == KEY_2 && change_iters(scene, 1)) ||
			(key == KEY_1 && change_iters(scene, -1)) ||
			(key == KEY_LEFT && change_palette_size(scene, -1)) ||
			(key == KEY_RIGHT && change_palette_size(scene, 1)) ||
			(key == KEY_UP && increment_pow_n(scene, 1)) ||
			(key == KEY_DOWN && increment_pow_n(scene, -1));
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
