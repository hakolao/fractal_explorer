/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_foreach.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 11:33:41 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/05 17:51:52 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_pixel_foreach(t_pixel_bounds *limits, void *params,
			void (*f)(int pixel_i, int x, int y, void *params))
{
	int		x;
	int		y;
	int		x0;
	int		y0;

	y = limits->y_start;
	y0 = 0;
	while (y < limits->y_end)
	{
		x = limits->x_start;
		x0 = 0;
		while (x < limits->x_end)
		{
			f(y0 * (limits->x_end - limits->x_start) + x0, x, y, params);
			x++;
			x0++;
		}
		y++;
		y0++;
	}
}
