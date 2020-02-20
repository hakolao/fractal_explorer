/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:22:18 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/20 14:56:27 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				handle_key_press(int key, void *param)
{
	t_scene		*scene;
	int			ret;

	scene = (t_scene *)param;
	if (key == KEY_ESC)
		handle_exit_event(scene);
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
			(key == KEY_DOWN && increment_pow_n(scene, -1)) ||
			(key == KEY_Q && flip_cx_sign(scene)) ||
			(key == KEY_E && flip_cy_sign(scene)) ||
			(key == KEY_P && save_image(scene));
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
