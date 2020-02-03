/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   guide.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 22:09:12 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/03 17:09:00 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

char			*key_guide(t_scene *scene)
{
	char	*guide;

	if ((scene->show_guide && (guide = ft_strdup("USAGE Keys:\n"
			"----------\nESC: Exit\nG: Toggle guide\n"
			"LOLOLOLOL")) == NULL) ||
		(!scene->show_guide && (guide = ft_strdup("USAGE Keys:\n"
			"----------\nESC: Exit\n"
			"G: Toggle guide")) == NULL))
		return (NULL);
	return (guide);
}

char			*mouse_guide(t_scene *scene)
{
	char	*guide;

	if ((scene->show_guide && (guide = ft_strdup("USAGE Mouse:\n"
			"----------\n"
			"LOLOLOLOL")) == NULL) ||
		(!scene->show_guide && (guide = ft_strdup("")) == NULL))
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
