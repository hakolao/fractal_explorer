/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 14:12:03 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/19 22:11:22 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_pixel_bounds		*pixel_bounds(int x_start, int x_end, int y_start,
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

static t_pixel				**thread_pixels(int size)
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

/*
** Sets renders specific fractal params that are then used
** in drawing pixel data on screen.
*/

int							thread_render_params(t_fractal_params
							*fractal_params, t_scene *scene, int i)
{
	if (!(fractal_params->pixel_bounds = pixel_bounds(0,
			scene->screen_width, i * (scene->screen_height / THREADS),
			(i + 1) * (scene->screen_height / THREADS))) ||
		!(fractal_params->pixels = thread_pixels(PIXELS)) ||
		!(fractal_params->frame = mlx_new_image(scene->mlx,
			scene->screen_width, scene->screen_height / THREADS)) ||
		!(fractal_params->frame_buf = mlx_get_data_addr(fractal_params->frame,
			&scene->pixel_bits, &scene->line_bytes, &scene->pixel_endian)))
		return (FALSE);
	return (TRUE);
}

/*
** Allocates and sets thread specific fractal params
*/

t_fractal_params			**thread_fractal_params(t_scene *scene)
{
	t_fractal_params		**fractal_params;
	int						i;

	if (!(fractal_params = malloc(sizeof(*fractal_params) * THREADS)) ||
		(scene->screen_height % THREADS != 0 &&
			log_err("HEIGHT % THREADS != 0", "Headers")))
		return (NULL);
	i = 0;
	while (i < THREADS)
	{
		if (!(fractal_params[i] =
				malloc(sizeof(**fractal_params) * PIXELS)) ||
			!select_params(scene->artist)(fractal_params[i], scene, i))
			return (NULL);
		i++;
	}
	return (fractal_params);
}

/*
** This function performs parallel work (worker_f), which takes in
** an array of thread params (size of thread_params should be the
** same as number of threads). For example, see draw_mandelbrot.
** After the work, threads are joined back.
*/

void						work_parallel(int num_threads, void **thread_params,
							void (*worker_f)(void *params))
{
	pthread_t				threads[num_threads];
	int						i;

	i = 0;
	while (i < num_threads)
	{
		if (pthread_create(&threads[i], NULL, (void*)worker_f,
			thread_params[i]))
			log_perr("Something went wrong in thread creation.");
		i++;
	}
	i = 0;
	while (i < num_threads)
		pthread_join(threads[i++], NULL);
}
