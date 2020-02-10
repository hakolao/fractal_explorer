/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:22:48 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/10 12:34:11 by ohakola          ###   ########.fr       */
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
		scene->mouse_x = x;
		scene->mouse_y = y;
	}
	scene->redraw = TRUE;
	return ((button == SCROLL_UP && zoom(scene, 1)) ||
			(button == SCROLL_DOWN && zoom(scene, -1)));
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
	int		x_diff;
	int		y_diff;
	int		diff_lim;

	scene = (t_scene *)param;
	x_diff = x - scene->mouse_x;
	y_diff = y - scene->mouse_y;
	diff_lim = 5;
	if (scene->mouse_left_pressed == TRUE && ft_abs(x_diff) > diff_lim &&
		move_by(scene, x_diff > 0 ? -0.01 : 0.01, 0))
		scene->mouse_x = x;
	else if (scene->mouse_left_pressed == TRUE && ft_abs(y_diff) > diff_lim &&
		move_by(scene, 0, y_diff > 0 ? -0.01 : 0.01))
		scene->mouse_y = y;
	if (scene->mouse_left_pressed)
		scene->redraw = TRUE;
	return (1);
}
