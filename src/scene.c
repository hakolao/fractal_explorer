/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:13:53 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/10 19:27:18 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int				scene_render_params(t_scene *scene,
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
	scene->redraw = TRUE;
	scene->col_r = 0;
	scene->col_g = 0;
	scene->col_b = 0;
	scene->col_a = 0;
	return (TRUE);
}

static t_fractal_params	**thread_fractal_params(t_scene *scene)
{
	t_fractal_params		**fractal_params;
	int						i;

	if (!(fractal_params = malloc(sizeof(*fractal_params) * THREADS)) ||
		(HEIGHT % THREADS != 0 && log_err("HEIGHT % THREADS != 0", "Headers")))
		return (NULL);
	i = 0;
	while (i < THREADS)
	{
		if (!(fractal_params[i] =
				malloc(sizeof(**fractal_params) * PIXELS)) ||
			!mandelbrot_params(fractal_params[i], scene, i))
			return (NULL);
		i++;
	}
	return (fractal_params);
}

t_scene					*new_scene(void *mlx, void *mlx_wdw)
{
	t_scene		*scene;

	if ((scene = (t_scene*)malloc(sizeof(*scene))) == NULL)
		return (NULL);
	if (scene_render_params(scene, mlx, mlx_wdw) == FALSE)
		return (NULL);
	scene->mouse_left_pressed = FALSE;
	scene->mouse_x = FALSE;
	scene->mouse_y = FALSE;
	scene->show_guide = FALSE;
	scene->artist = mandelbrot;
	if (!(scene->fractal_params = thread_fractal_params(scene)))
		return (NULL);
	return (scene);
}
