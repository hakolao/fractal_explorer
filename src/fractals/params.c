/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   params.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:13:05 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/12 13:43:15 by ohakola          ###   ########.fr       */
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

static int				thread_render_params(t_fractal_params *fractal_params,
						t_scene *scene, int i)
{
	if (!(fractal_params->pixel_bounds = pixel_bounds(0, WIDTH,
			i * (HEIGHT / THREADS), (i + 1) * (HEIGHT / THREADS))) ||
		!(fractal_params->pixels = thread_pixels(PIXELS)) ||
		!(fractal_params->frame = mlx_new_image(scene->mlx,
			WIDTH, HEIGHT / THREADS)) ||
		!(fractal_params->frame_buf = mlx_get_data_addr(fractal_params->frame,
			&scene->pixel_bits, &scene->line_bytes, &scene->pixel_endian)))
		return (FALSE);
	return (TRUE);
}

int						mandelbrot_params(t_fractal_params
						*fractal_params, t_scene *scene, int i)
{
	fractal_params->max_iter = MAX_ITER_INIT;
	fractal_params->zoom = 1.0;
	fractal_params->size = PIXELS;
	fractal_params->center_x = MANDEL_CENTER_X;
	fractal_params->center_y = MANDEL_CENTER_Y;
	fractal_params->min_x = -2.0;
	fractal_params->max_x = 2.0;
	fractal_params->min_y = -2.0;
	fractal_params->max_y = 2.0;
	fractal_params->thread_i = i;
	fractal_params->width = WIDTH;
	fractal_params->height = HEIGHT / THREADS;
	if (!color_palette(fractal_params, scene->colors, 6,
			scene->palette_size) ||
		!thread_render_params(fractal_params, scene, i))
		return (FALSE);
	return (TRUE);
}

int						julia_params(t_fractal_params
						*fractal_params, t_scene *scene, int i)
{
	fractal_params->max_iter = MAX_ITER_INIT;
	fractal_params->zoom = 1.0;
	fractal_params->size = PIXELS;
	fractal_params->center_x = JULIA_CENTER_X;
	fractal_params->center_y = JULIA_CENTER_Y;
	fractal_params->r = 2.0;
	fractal_params->min_x = -fractal_params->r;
	fractal_params->max_x = fractal_params->r;
	fractal_params->min_y = -fractal_params->r;
	fractal_params->max_y = fractal_params->r;
	fractal_params->cx = -0.7;
	fractal_params->cy = 0.27015;
	fractal_params->thread_i = i;
	fractal_params->width = WIDTH;
	fractal_params->height = HEIGHT / THREADS;
	if (!color_palette(fractal_params, scene->colors, 6,
			scene->palette_size) ||
		!thread_render_params(fractal_params, scene, i))
		return (FALSE);
	return (TRUE);
}
