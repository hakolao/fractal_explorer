/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 14:10:51 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/23 19:21:32 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_colors			*default_colors(void)
{
	t_colors	*color_data;
	t_rgb		*color_input;
	t_rgb		**colors;
	int			i;

	color_input = (t_rgb[6]){{255, 0, 0}, {255, 255, 0},
		{0, 255, 0}, {0, 255, 255}, {0, 0, 255}, {255, 0, 255}};
	if (!(color_data = malloc(sizeof(*color_data))))
		return (NULL);
	if (!(colors = malloc(sizeof(t_rgb*) * 6)))
		return (NULL);
	i = 0;
	while (i < 6)
	{
		if (!(colors[i] = malloc(sizeof(t_rgb*))))
			return (NULL);
		colors[i]->r = color_input[i].r;
		colors[i]->g = color_input[i].g;
		colors[i]->b = color_input[i].b;
		i++;
	}
	color_data->colors = colors;
	color_data->size = 6;
	return (color_data);
}

int					color_palette(t_fractal_params *params,
					t_rgb **colors, int col_size, int size)
{
	int		i;
	int		j;
	int		lim;
	double	mul;

	if (!(params->palette = malloc(sizeof(*params->palette) * size)))
		return (FALSE);
	i = -1;
	j = -1;
	lim = ceil((double)size / (col_size > 1 ? col_size - 1 : col_size));
	while (++i < size)
	{
		if (i % lim == 0)
			j++;
		mul = (double)(i % lim) / lim;
		if (j == col_size - 1)
			j--;
		params->palette[i] = COLOR(colors[0]->r, colors[0]->g,
			colors[0]->b, 0);
		if (col_size > 1)
			params->palette[i] = lerp_rgb(COLOR(colors[j]->r, colors[j]->g,
			colors[j]->b, 0), COLOR(colors[j + 1]->r, colors[j + 1]->g,
			colors[j + 1]->b, 0), mul);
	}
	return (!!(params->palette_size = size));
}

int					randomize_palette(t_scene *scene)
{
	int		i;
	int		r;
	int		g;
	int		b;

	i = -1;
	while (++i < scene->colors_size)
	{
		scene->colors[i]->r = scene->colors[i]->r > 0 &&
			(r = rand() % 255) > 0 ? r : scene->colors[i]->r;
		scene->colors[i]->g = scene->colors[i]->g > 0 &&
			(g = rand() % 255) > 0 ? g : scene->colors[i]->g;
		scene->colors[i]->b = scene->colors[i]->b > 0 &&
			(b = rand() % 255) > 0 ? b : scene->colors[i]->b;
	}
	i = -1;
	while (++i < THREADS)
	{
		free(scene->fractal_params[i]->palette);
		if (!color_palette(scene->fractal_params[i], scene->colors,
			scene->colors_size, scene->palette_size))
			return (FALSE);
	}
	return (FALSE);
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
		free(scene->fractal_params[i]->palette);
		if (!color_palette(scene->fractal_params[i], scene->colors,
			scene->colors_size, scene->palette_size))
			return (FALSE);
		i++;
	}
	return (0);
}

int					free_colors_str(char **color_strs, int size)
{
	int		i;

	i = -1;
	while (++i < size)
		ft_strdel(&color_strs[i]);
	free(color_strs);
	return (1);
}
