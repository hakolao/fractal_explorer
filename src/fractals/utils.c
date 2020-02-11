/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:29:37 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/11 13:21:48 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int						color_palette(t_fractal_params *params,
						t_rgb **colors, int colors_size, int palette_size)
{
	int		i;
	int		j;
	int		lim;
	double	mul;

	if (!(params->color_palette =
			malloc(sizeof(*params->color_palette) * palette_size)))
		return (FALSE);
	i = 0;
	j = 0;
	lim = palette_size / (colors_size - 1);
	while (i < palette_size)
	{
		mul = (double)(i % lim) / lim;
		params->color_palette[i] = lerp_rgb(
			COLOR(colors[j]->r, colors[j]->g, colors[j]->b, 0),
			COLOR(colors[j + 1]->r, colors[j + 1]->g, colors[j + 1]->b, 0),
			i != 0 && mul == 0.0 ? 1.0 : mul);
		if (i % lim == 0 && i != 0)
			j++;
		i++;
	}
	return (TRUE);
}

int						zoom(t_scene *scene, double amount)
{
	int	i;

	i = 0;
	while (i < THREADS)
	{
		scene->fractal_params[i]->zoom += amount;
		scene->fractal_params[i]->zoom_mul = pow(0.97,
			scene->fractal_params[i]->zoom);
		scene->fractal_params[i]->max_iter += amount > 0 ? 1 : -1;
		i++;
	}
	return (0);
}

int						move_by(t_scene *scene, double x_amount,
						double y_amount)
{
	int		i;

	i = 0;
	while (i < THREADS)
	{
		scene->fractal_params[i]->center_x +=
			x_amount * scene->fractal_params[i]->zoom_mul;
		scene->fractal_params[i]->center_y +=
			y_amount * scene->fractal_params[i]->zoom_mul;
		i++;
	}
	return (0);
}

int						change_iters(t_scene *scene, double amount)
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
