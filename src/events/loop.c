/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 18:23:34 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/20 15:34:03 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** Handle drawing of screen in app loop
*/

int				handle_loop(void *params)
{
	t_scenes		*data;
	int				i;

	data = (t_scenes*)params;
	i = 0;
	while (i < data->size)
	{
		if (data->scenes[i] &&
			data->scenes[i]->redraw == TRUE)
			draw(data->scenes[i]);
		i++;
	}
	return (0);
}
