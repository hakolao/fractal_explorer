/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:13:53 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/03 16:55:05 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					scene_render_params(t_scene *scene,
					void *mlx, void *mlx_wdw)
{
	scene->mlx = mlx;
	scene->mlx_wdw = mlx_wdw;
	scene->pixel_bits = 32;
	scene->line_bytes = WIDTH * 4;
	scene->pixel_endian = TRUE;
	if (!(scene->frame = mlx_new_image(mlx, WIDTH, HEIGHT)) ||
		!(scene->frame_buf =
			mlx_get_data_addr(scene->frame, &scene->pixel_bits,
			&scene->line_bytes, &scene->pixel_endian)))
		return (FALSE);
	scene->redraw = FALSE;
	scene->col_r = 0;
	scene->col_g = 0;
	scene->col_b = 0;
	scene->col_a = 0;
	return (TRUE);
}

/*
** Creates a new scene containing all needed information. Set's
** camera's position based on map's size
*/

t_scene				*new_scene(void *mlx, void *mlx_wdw)
{
	t_scene		*scene;

	if ((scene = (t_scene*)malloc(sizeof(*scene))) == NULL)
		return (NULL);
	if (scene_render_params(scene, mlx, mlx_wdw) == FALSE)
		return (NULL);
	scene->mouse_right_pressed = FALSE;
	scene->mouse_left_pressed = FALSE;
	scene->shift_pressed = FALSE;
	scene->mouse_x = FALSE;
	scene->mouse_y = FALSE;
	scene->show_guide = FALSE;
	scene->show_coords = FALSE;
	return (scene);
}
