/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 12:29:37 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/10 12:09:22 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_pixel_bounds	*pixel_bounds(int x_start, int x_end, int y_start,
						int y_end)
{
	t_pixel_bounds	*bounds;

	if (!(bounds = malloc(sizeof(*bounds))))
		return (NULL);
	bounds->x_start = x_start;
	bounds->x_end = x_end;
	bounds->y_start = y_start;
	bounds->y_end = y_end;
	return (bounds);
}

static t_pixel			**thread_pixels(int size)
{
	t_pixel					**pixels;
	int						i;

	if (!(pixels = malloc(sizeof(*pixels) * size)))
		return (NULL);
	i = 0;
	while (i < size)
		if (!(pixels[i++] = malloc(sizeof(**pixels))))
			return (NULL);
	return (pixels);
}

int						palette(t_fractal_params *params,
						t_rgb *palette, int palette_size)
{
	int		i;
	int		j;
	int		lim;
	double	mul;

	if (!(params->color_palette =
			malloc(sizeof(*params->color_palette) * COLORS)))
		return (FALSE);
	i = 0;
	j = 0;
	lim = COLORS / (palette_size - 1);
	while (i < COLORS)
	{
		mul = (double)(i % lim) / lim;
		params->color_palette[i] = lerp_rgb(
			COLOR(palette[j].r, palette[j].g, palette[j].b, 0),
			COLOR(palette[j + 1].r, palette[j + 1].g, palette[j + 1].b, 0),
			i != 0 && mul == 0.0 ? 1.0 : mul);
		if (i % lim == 0 && i != 0)
			j++;
		i++;
	}
	return (TRUE);
}

int						mandelbrot_params(t_fractal_params
						*fractal_params, t_scene *scene, int i)
{
	if (!fractal_params)
		return (FALSE);
	fractal_params->max_iter = scene->max_iter;
	fractal_params->zoom = 1.0;
	fractal_params->zoom_mul = 1.0;
	fractal_params->size = PIXELS;
	fractal_params->center_x = -0.7746806106269039;
	fractal_params->center_y = -0.1374168856037867;
	fractal_params->min_x = -2.5;
	fractal_params->max_x = 1.0;
	fractal_params->min_y = -1.0;
	fractal_params->max_y = 1.0;
	if (!(fractal_params->pixel_bounds = pixel_bounds(0, WIDTH,
			i * (HEIGHT / THREADS), (i + 1) * (HEIGHT / THREADS))) ||
		!(fractal_params->pixels = thread_pixels(PIXELS)) ||
		!palette(fractal_params, (t_rgb[6]){{255, 0, 0}, {255, 255, 0},
			{0, 255, 0}, {0, 255, 255}, {0, 0, 255}, {255, 0, 255}}, 6))
		return (FALSE);
	return (TRUE);
}

int						zoom(t_scene *scene, double amount)
{
	int	i;

	i = 0;
	while (i < THREADS)
	{
		scene->fractal_params[i]->zoom += amount;
		scene->fractal_params[i]->zoom_mul = pow(0.95,
			scene->fractal_params[i]->zoom);
		scene->fractal_params[i]->max_iter += amount > 0 ? 2 : -2;
		i++;
	}
	return (0);
}

int						center_to(t_scene *scene, double mouse_x,
						double mouse_y)
{
	int		i;
	double	scaled_x;
	double	scaled_y;
	double	x_diff;
	double	y_diff;

	i = 0;
	scaled_x = (scene->fractal_params[i]->min_x + mouse_x *
		(scene->fractal_params[i]->max_x - scene->fractal_params[i]->min_x) / WIDTH);
	scaled_y = (scene->fractal_params[i]->min_y + mouse_y *
		(scene->fractal_params[i]->max_y - scene->fractal_params[i]->min_y) / HEIGHT);
	x_diff = scene->fractal_params[i]->center_x - scaled_x;
	y_diff = scene->fractal_params[i]->center_y - scaled_y;
	// printf("x_diff: %f, y_diff: %f\ncenter_x: %f, center_y: %f\n", x_diff, y_diff,
	// 	scene->fractal_params[i]->center_x, scene->fractal_params[i]->center_y);
	while (i < THREADS)
	{
		scene->fractal_params[i]->center_x -= x_diff;
		scene->fractal_params[i]->center_y -= y_diff;
		i++;
	}
	return (0);
}