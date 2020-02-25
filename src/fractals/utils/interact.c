/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interact.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 23:23:33 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/25 14:14:54 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				increment_pow_n(t_scene *scene, int incr)
{
	int			i;

	if (!(scene->artist == mandelbrot_n ||
			scene->artist == julia_n))
		return (0);
	i = 0;
	while (i < THREADS)
	{
		scene->fractal_params[i]->pow_n += incr;
		if (scene->fractal_params[i]->pow_n <= 2)
			scene->fractal_params[i]->pow_n = 2;
		else if (scene->fractal_params[i]->pow_n >= 100)
			scene->fractal_params[i]->pow_n = 100;
		i++;
	}
	return (0);
}

int				change_iters(t_scene *scene, long double amount)
{
	int		i;

	i = 0;
	while (i < THREADS)
	{
		scene->fractal_params[i]->max_iter += amount;
		i++;
	}
	return (0);
}
