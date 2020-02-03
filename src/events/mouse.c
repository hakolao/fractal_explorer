/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:22:48 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/03 17:08:30 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				handle_mouse_button_press(int button, int x, int y, void *param)
{
	t_scene		*scene;

	scene = (t_scene *)param;
	(void)x;
	(void)y;
	(void)button;
	scene->redraw = TRUE;
	return (1);
}

int				handle_mouse_button_release(int button, int x, int y,
				void *param)
{
	t_scene	*scene;

	scene = (t_scene *)param;
	(void)x;
	(void)y;
	(void)button;
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
	if (scene->mouse_right_pressed == TRUE && ft_abs(x_diff) > diff_lim &&
		1)
		scene->mouse_x = x;
	else if (scene->mouse_right_pressed == TRUE && ft_abs(y_diff) > diff_lim &&
		1)
		scene->mouse_y = y;
	else if (scene->mouse_left_pressed == TRUE && ft_abs(x_diff) > diff_lim &&
		1)
		scene->mouse_x = x;
	else if (scene->mouse_left_pressed == TRUE && ft_abs(y_diff) > diff_lim &&
		1)
		scene->mouse_y = y;
	if (scene->mouse_left_pressed || scene->mouse_right_pressed)
		scene->redraw = TRUE;
	return (1);
}
