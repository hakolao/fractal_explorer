/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 17:08:46 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/12 16:34:34 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				handle_exit_event(void *params)
{
	t_scene	*scene;

	scene = (t_scene*)params;
	mlx_destroy_window(scene->mlx, scene->mlx_wdw);
	return (0);
}
