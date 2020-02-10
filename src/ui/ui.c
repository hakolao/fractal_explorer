/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 15:03:35 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/10 19:11:53 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void				draw_ui(t_scene *scene)
{
	char	*guidestr;
	char	*iterations;
	char	*iterstr;

	if (!(guidestr = guide(scene)) ||
		!(iterations = ft_itoa(scene->fractal_params[0]->max_iter)) ||
		!(iterstr = ft_strjoin("Max iters: ", iterations)))
		return ;
	draw_paragraph(scene, guidestr, 10, 60);
	if (scene->show_guide)
		draw_paragraph(scene, iterstr, WIDTH - 200, 60);
	ft_strdel(&guidestr);
	ft_strdel(&iterations);
	ft_strdel(&iterstr);
}
