/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 22:09:12 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/11 13:27:18 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char			*guide(void)
{
	char	*guide;

	if ((guide = ft_strdup("USAGE Keys:\n"
			"----------\nESC: Exit\nG: Toggle guide\n"
			"Scroll: Zoom in/out (increases max iters)\n"
			"Mouse button 1: Drag to move\n"
			"Keys 1 & 2: Increase max iterations")) == NULL)
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
			ypos + i * 20, UI_COLOR, split_text[i]);
		ft_strdel(&split_text[i++]);
	}
	free(split_text);
}
