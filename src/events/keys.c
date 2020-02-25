/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:22:18 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/25 14:29:55 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				handle_key_press(int key, void *param)
{
	t_scene		*scene;
	int			ret;

	scene = (t_scene *)param;
	if (key == KEY_G)
		scene->show_guide = !scene->show_guide;
	if (key == KEY_SHIFT)
		scene->toggle_zoom_center = !scene->toggle_zoom_center;
	ret = (key == KEY_W && zoom(scene, 1.03, WIDTH / 2, HEIGHT / 2)) ||
		(key == KEY_S && zoom(scene, 1 / 1.03, WIDTH / 2, HEIGHT / 2)) ||
		(key == KEY_2 && change_iters(scene, 1)) ||
		(key == KEY_1 && change_iters(scene, -1)) ||
		(key == KEY_Q && change_palette_size(scene, -1)) ||
		(key == KEY_E && change_palette_size(scene, 1)) ||
		(key == KEY_NUM_PLUS && increment_pow_n(scene, 1)) ||
		(key == KEY_NUM_MINUS && increment_pow_n(scene, -1)) ||
		(key == KEY_UP && move_x_y(scene, 0, -1)) ||
		(key == KEY_DOWN && move_x_y(scene, 0, 1)) ||
		(key == KEY_LEFT && move_x_y(scene, -1, 0)) ||
		(key == KEY_RIGHT && move_x_y(scene, 1, 0)) ||
		(key == KEY_P && save_image(scene)) ||
		(key == KEY_TAB && change_ui_colors(scene)) ||
		(key == KEY_C && randomize_palette(scene)) ||
		(key == KEY_ESC && handle_exit_event(scene));
	return ((scene->redraw = TRUE));
}

int				handle_key_release(int key, void *param)
{
	t_scene		*scene;

	scene = (t_scene *)param;
	(void)key;
	return (0);
}
