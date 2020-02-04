/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_foreach.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:33:41 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/04 14:54:30 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_pixel_foreach(t_pixels limits, void *params,
			void (*f)(t_pixel pixel, void *params))
{
	t_pixel	pixel;

	pixel.y = limits.y_start - 1;
	while (++pixel.y < limits.y_end)
	{
		pixel.x = limits.x_start - 1;
		while (++pixel.x < limits.x_end)
			f(pixel, params);
		pixel.y++;
	}
}
