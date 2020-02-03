/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:03:35 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/03 17:00:11 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				draw_ui(t_scene *scene)
{
	char	*mouse_g;
	char	*key_g;

	if ((mouse_g = mouse_guide(scene)) == NULL ||
		(key_g = key_guide(scene)) == NULL)
		return ;
	draw_paragraph(scene, key_g, 10, 60);
	draw_paragraph(scene, mouse_g, 10, 650);
	ft_strdel(&mouse_g);
	ft_strdel(&key_g);
}
