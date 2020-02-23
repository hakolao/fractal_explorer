/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 22:09:12 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/23 16:31:59 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char			*guide(void)
{
	char	*guide;

	if ((guide = ft_strdup("USAGE Keys:\n"
			"----------\nESC: Exit all\n(x): Exit window\n"
			"G: Toggle guide\n"
			"Scroll/W/S: Zoom in/out (increases max iters)\n"
			"Mouse 1: Center to point\n"
			"C: Change color palette\n"
			"Tab: Change UI color\n"
			"P: Render an image of size (IMG_WIDTH, IMG_HEIGHT)\n"
			"Left/Right: Change palette size\n"
			"Mouse 2: Stop Julia cx cy\n"
			"Mouse Middle: Stop phoenix_mod px, py\n"
			"Q/E: Flip cx, cy signs (in julia_mod)\n"
			"Up/Down: Increment pow_n (only [fractal]_n])\n")) == NULL)
		return (NULL);
	return (guide);
}

void			draw_paragraph(t_scene *scene, char *text, int xpos,
				int ypos)
{
	char	**split_text;
	int		i;

	if (!text || (split_text = ft_strsplit(text, '\n')) == NULL)
		return ;
	i = 0;
	while (split_text[i])
	{
		mlx_string_put(scene->mlx, scene->mlx_wdw, xpos,
			ypos + i * 20, scene->ui_color, split_text[i]);
		ft_strdel(&split_text[i++]);
	}
	free(split_text);
}
