/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:29:37 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/11 16:56:27 by ohakola          ###   ########.fr       */
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
	i = -1;
	j = -1;
	lim = ceil((double)palette_size / (colors_size - 1));
	while (++i < palette_size)
	{
		if (i % lim == 0)
			j++;
		mul = (double)(i % lim) / lim;
		if (j == colors_size - 1)
			j--;
		params->color_palette[i] = lerp_rgb(
			COLOR(colors[j]->r, colors[j]->g, colors[j]->b, 0),
			COLOR(colors[j + 1]->r, colors[j + 1]->g, colors[j + 1]->b, 0),
			mul);
	}
	params->palette_size = palette_size;
	return (TRUE);
}

int						zoom(t_scene *scene, long double amount)
{
	int	i;

	i = 0;
	while (i < THREADS)
	{
		scene->fractal_params[i]->zoom *= amount;
		scene->fractal_params[i]->max_iter += amount > 1 ? 1 : -1;
		i++;
	}
	return (0);
}

int						move_by(t_scene *scene, long double x_amount,
						long double y_amount)
{
	int		i;

	i = 0;
	while (i < THREADS)
	{
		scene->fractal_params[i]->center_x +=
			x_amount / scene->fractal_params[i]->zoom;
		scene->fractal_params[i]->center_y +=
			y_amount / scene->fractal_params[i]->zoom;
		i++;
	}
	return (0);
}

int						change_iters(t_scene *scene, long double amount)
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

long double				*scaled_xy(long double *x0_y0,
						t_fractal_params *params, int px, int py)
{
	long double	min_x0;
	long double	min_y0;
	long double	max_x0;
	long double	max_y0;

	min_x0 = params->min_x;
	max_x0 = params->max_y;
	min_y0 = params->min_y;
	max_y0 = params->max_y;
	x0_y0[0] = (min_x0 + px * (max_x0 - min_x0) / WIDTH) /
		params->zoom + params->center_x;
	x0_y0[1] = (min_y0 + py * (max_y0 - min_y0) / HEIGHT) /
		params->zoom + params->center_y;
	return (x0_y0);
}
