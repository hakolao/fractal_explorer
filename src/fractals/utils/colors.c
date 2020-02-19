/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:10:51 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/19 17:08:49 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int					scene_colors(t_scene *scene)
{
	t_rgb	*colors;
	int		i;

	colors = (t_rgb[6]){{255, 0, 0}, {255, 255, 0},
		{0, 255, 0}, {0, 255, 255}, {0, 0, 255}, {255, 0, 255}};
	if (!(scene->colors = malloc(sizeof(t_rgb*) * 6)))
		return (FALSE);
	i = 0;
	while (i < 6)
	{
		if (!(scene->colors[i] = malloc(sizeof(t_rgb))))
			return (FALSE);
		scene->colors[i]->r = colors[i].r;
		scene->colors[i]->g = colors[i].g;
		scene->colors[i]->b = colors[i].b;
		i++;
	}
	return (TRUE);
}

int					color_palette(t_fractal_params *params,
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

int					randomize_palette(t_scene *scene)
{
	int		i;
	t_rgb	*colors;

	colors = (t_rgb[6]){
			{rand() % 255, 0, 0}, {rand() % 255, rand() % 255, 0},
			{0, rand() % 255, 0}, {0, rand() % 255, rand() % 255},
			{0, 0, rand() % 255}, {rand() % 255, 0, rand() % 255}};
	i = -1;
	while (++i < 6)
	{
		scene->colors[i]->r = colors[i].r;
		scene->colors[i]->g = colors[i].g;
		scene->colors[i]->b = colors[i].b;
	}
	i = -1;
	while (++i < THREADS)
	{
		free(scene->fractal_params[i]->color_palette);
		if (!color_palette(scene->fractal_params[i], scene->colors, 6,
			scene->palette_size))
			return (FALSE);
	}
	return (0);
}

int					change_palette_size(t_scene *scene, int amount)
{
	int		i;

	if (scene->palette_size == 12 && amount < 0)
		return (FALSE);
	scene->palette_size += amount;
	i = 0;
	while (i < THREADS)
	{
		free(scene->fractal_params[i]->color_palette);
		if (!color_palette(scene->fractal_params[i], scene->colors, 6,
			scene->palette_size))
			return (FALSE);
		i++;
	}
	return (0);
}

/*
** https://linas.org/art-gallery/escape/smooth.html
*/

void				smooth_color_pixel(t_pixel *pixel, long double iter,
					t_complex squares, t_fractal_params *params)
{
	iter = iter + 1.0 - log(log(squares.r + squares.i)) / log(params->pow_n);
	pixel->color = lerp_rgb(params->color_palette[
			(int)floor(iter) % params->palette_size],
		params->color_palette[
			(int)((floor(iter)) + 1) % params->palette_size],
		iter - floor(iter));
}
