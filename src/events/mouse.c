/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:22:48 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/20 18:54:42 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				handle_mouse_button_press(int button, int x, int y, void *param)
{
	t_scene		*scene;

	scene = (t_scene *)param;
	if (button == MOUSE_BUTTON_LEFT)
	{
		scene->mouse_left_pressed = TRUE;
		center_to(scene, x, y);
	}
	if ((scene->artist == julia || scene->artist == julia_n ||
		scene->artist == julia_mod || scene->artist == phoenix_mod ||
		scene->artist == burning_julia)
		&& button == MOUSE_BUTTON_RIGHT)
		scene->stop_julia = !scene->stop_julia;
	if (scene->artist == phoenix_mod && button == MOUSE_BUTTON_MIDDLE)
		scene->stop_phoenix_mod = !scene->stop_phoenix_mod;
	scene->redraw = TRUE;
	return ((button == SCROLL_UP && zoom(scene, 1.03)) ||
			(button == SCROLL_DOWN && zoom(scene, 1 / 1.03)));
}

int				handle_mouse_button_release(int button, int x, int y,
				void *param)
{
	t_scene	*scene;

	(void)x;
	(void)y;
	scene = (t_scene *)param;
	if (button == MOUSE_BUTTON_LEFT)
		scene->mouse_left_pressed = FALSE;
	scene->redraw = TRUE;
	return (1);
}

int				handle_mouse_move(int x, int y, void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	if ((scene->artist == julia || scene->artist == julia_n ||
		scene->artist == julia_mod || scene->artist == phoenix_mod ||
		scene->artist == burning_julia)
		&& !scene->stop_julia &&
		move_cx_cy(scene, x, y))
		scene->redraw = TRUE;
	if (scene->artist == phoenix_mod && !scene->stop_phoenix_mod &&
		move_px_py(scene, x, y))
		scene->redraw = TRUE;
	return (1);
}
