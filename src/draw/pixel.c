/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 13:18:55 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/03 17:08:01 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			plot_pixel(t_scene *scene, int x, int y, int color)
{
	int	pixel;

	pixel = (y * scene->line_bytes) + (x * 4);
	if (pixel > 0 && pixel < HEIGHT * WIDTH * 4)
	{
		scene->frame_buf[pixel + 0] = BLUE(color);
		scene->frame_buf[pixel + 1] = GREEN(color);
		scene->frame_buf[pixel + 2] = RED(color);
		scene->frame_buf[pixel + 3] = ALPHA(color);
	}
}
