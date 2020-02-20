/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:08:46 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/20 15:41:11 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				handle_exit_event(void *params)
{
	t_scene		*scene;
	t_scenes	*data;
	int			i;
	int			should_exit;

	scene = (t_scene*)params;
	data = scene->data;
	mlx_destroy_window(scene->mlx, scene->mlx_wdw);
	should_exit = TRUE;
	i = -1;
	while (++i < data->size)
	{
		if (i == scene->id && !(data->scenes[i] = NULL))
			delete_scene(scene);
		if (data->scenes[i] != NULL)
			should_exit = FALSE;
	}
	if (should_exit)
		exit(0);
	return (0);
}
