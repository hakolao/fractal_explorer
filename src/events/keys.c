/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:22:18 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/03 17:04:27 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				handle_key_press(int key, void *param)
{
	t_scene		*scene;

	scene = (t_scene *)param;
	scene->redraw = TRUE;
	if (key == KEY_ESC)
		exit(0);
	return (0);
}

int				handle_key_release(int key, void *param)
{
	t_scene		*scene;

	scene = (t_scene *)param;
	(void)key;
	return (0);
}
