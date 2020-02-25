/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:48:25 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/25 14:14:00 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			draw_power_info(t_scene *scene, int x, int y)
{
	char	*n_pow;

	if ((scene->artist == mandelbrot_n || scene->artist == julia_n) &&
		(n_pow = ft_itoa(scene->fractal_params[0]->pow_n)))
	{
		mlx_string_put(scene->mlx, scene->mlx_wdw, x, y + 80,
			scene->ui_color, "Pow n: ");
		mlx_string_put(scene->mlx, scene->mlx_wdw, x + 100, y + 80,
			scene->ui_color, n_pow);
		ft_strdel(&n_pow);
	}
}

void			draw_cx_cy_info(t_scene *scene, int x, int y)
{
	char	*cx;
	char	*cy;

	if ((cx = ft_ftoa(scene->fractal_params[0]->cx, 15)) &&
		(cy = ft_ftoa(scene->fractal_params[0]->cy, 15)))
	{
		mlx_string_put(scene->mlx, scene->mlx_wdw, x, y + 40,
			scene->ui_color, "Cx: ");
		mlx_string_put(scene->mlx, scene->mlx_wdw, x + 100, y + 40,
			scene->ui_color, cx);
		mlx_string_put(scene->mlx, scene->mlx_wdw, x, y + 60,
			scene->ui_color, "Cy: ");
		mlx_string_put(scene->mlx, scene->mlx_wdw, x + 100, y + 60,
			scene->ui_color, cy);
		ft_strdel(&cx);
		ft_strdel(&cy);
	}
}

void			draw_px_py_info(t_scene *scene, int x, int y)
{
	char	*px;
	char	*py;

	if (scene->artist == phoenix_mod &&
		(px = ft_ftoa(scene->fractal_params[0]->px, 15)) &&
		(py = ft_ftoa(scene->fractal_params[0]->py, 15)))
	{
		mlx_string_put(scene->mlx, scene->mlx_wdw, x, y + 80,
			scene->ui_color, "Px: ");
		mlx_string_put(scene->mlx, scene->mlx_wdw, x + 100, y + 80,
			scene->ui_color, px);
		mlx_string_put(scene->mlx, scene->mlx_wdw, x, y + 100,
			scene->ui_color, "Py: ");
		mlx_string_put(scene->mlx, scene->mlx_wdw, x + 100, y + 100,
			scene->ui_color, py);
		ft_strdel(&px);
		ft_strdel(&py);
	}
}

int				change_ui_colors(t_scene *scene)
{
	scene->ui_color =
		COLOR(rand() % 255, rand() % 255, rand() % 255, 255);
	return (0);
}
