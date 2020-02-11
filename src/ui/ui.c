/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:03:35 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/11 13:27:10 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void			draw_palette(t_scene *scene, int x, int y)
{
	int		color;
	char	*nbstr;
	int		i;
	int		px;
	int		py;

	mlx_string_put(scene->mlx, scene->mlx_wdw, x, y,
		UI_COLOR, "Palette, total colors: ");
	if (!(nbstr = ft_itoa(scene->palette_size)))
		return ;
	mlx_string_put(scene->mlx, scene->mlx_wdw, x + 250, y, UI_COLOR, nbstr);
	i = -1;
	while (++i < 6)
	{
		color = COLOR(scene->colors[i]->r,
			scene->colors[i]->g, scene->colors[i]->b, 0);
		py = y + 30 - 1;
		while (++py < y + 30 + 50)
		{
			px = x + i * 60 - 1;
			while (++px < x + i * 60 + 50)
				mlx_pixel_put(scene->mlx, scene->mlx_wdw, px, py, color);
		}
	}
	ft_strdel(&nbstr);
}

void				draw_ui(t_scene *scene)
{
	char	*guidestr;
	char	*iterations;
	char	*iterstr;

	if (!(guidestr = guide(scene)) ||
		!(iterations = ft_itoa(scene->fractal_params[0]->max_iter)) ||
		!(iterstr = ft_strjoin("Max iters: ", iterations)))
		return ;
	if (scene->show_guide)
	{
		draw_paragraph(scene, guidestr, 10, 60);
		draw_paragraph(scene, iterstr, WIDTH - 200, 60);
		draw_palette(scene, 10, HEIGHT - 90);
	}
	ft_strdel(&guidestr);
	ft_strdel(&iterations);
	ft_strdel(&iterstr);
}
