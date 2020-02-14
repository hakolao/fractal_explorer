/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 14:31:15 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/14 14:56:40 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int			flip_cx_sign(t_scene *scene)
{
	int		i;

	i = 0;
	while (i < THREADS)
	{
		scene->fractal_params[i]->cx_sign = -1 *
			scene->fractal_params[i]->cx_sign;
		i++;
	}
	return (0);
}

int			flip_cy_sign(t_scene *scene)
{
	int		i;

	i = 0;
	while (i < THREADS)
	{
		scene->fractal_params[i]->cy_sign = -1 *
			scene->fractal_params[i]->cy_sign;
		i++;
	}
	return (0);
}