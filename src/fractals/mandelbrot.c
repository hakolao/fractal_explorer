/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 10:46:22 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/05 18:15:11 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		set_thread_pixel(t_thread_pixel *pixel, int x, int y,
				int color_index)
{
	pixel->color_index = color_index;
	pixel->x = x;
	pixel->y = y;
}

static void		plot_mandelbrot(int pixel_i, int px, int py, void *params)
{
	double				x;
	double				y;
	double				x0;
	double				y0;
	double				rsquare;
	double				isquare;
	double				zsquare;
	// double			log_zn;
	double				iter;
	t_fractal_params	*fract;

	fract = (t_fractal_params*)params;
	x0 = ft_lmap_double((double)px,
		(double[2]){0, (double)WIDTH}, (double[2]){-2.5, 1.0});
	y0 = ft_lmap_double((double)py,
		(double[2]){0, (double)HEIGHT}, (double[2]){-1.0, 1.0});
    x = 0.0;
    y = 0.0;
	rsquare = 0.0;
	isquare = 0.0;
	zsquare = 0.0;
    iter = 0.0;
	while (rsquare + isquare <= (1 << 16) && iter < (fract->max_iter))
	{
		x = rsquare - isquare + x0;
		y = zsquare - rsquare - isquare + y0;
		rsquare = x * x;
		isquare = y * y;
		zsquare = (x + y) * (x + y);
		iter++;
		// if (iter < scene->max_iter)
		// {
		// 	log_zn = log(rsquare + isquare) / 2.0;
		// 	iter = iter + 1.0 - log(log_zn / log(2.0)) / log(2.0);		
		// }
		// plot_pixel(scene, pixel.x, pixel.y, lerp_rgb(
		// 	scene->color_palette[(int)floor(iter)],
		// 	scene->color_palette[(int)(floor(iter) + 1.0)],
		// 	iter - floor(iter)));
	}
	set_thread_pixel(fract->pixels[pixel_i], px, py, floor(iter));
}

static void		*plot_mandelbrot_thread(void *params)
{
	t_fractal_params *fractal;

	fractal = (t_fractal_params*)params;

	ft_pixel_foreach(fractal->pixel_bounds, params,
		plot_mandelbrot);
	return (NULL);
}

static void		plot_threaded_pixels(t_scene *scene)
{
	int				i;
	int				j;
	int				color;
	t_thread_pixel	*pixel;

	i = 0;
	while (i < THREADS)
	{
		j = 0;
		while (j < scene->fractal_params[i]->size)
		{
			pixel = scene->fractal_params[i]->pixels[j];
			color = scene->color_palette[pixel->color_index];
			plot_pixel(scene, pixel->x, pixel->y, color);
			j++;
		}
		i++;
	}
}

void			draw_mandelbrot(t_scene *scene)
{
	pthread_t				threads[THREADS];
	int						size;
	int						i;

	size = WIDTH * HEIGHT / THREADS;
	i = 0;
	while (i < THREADS)
	{
		if (pthread_create(&threads[i], NULL, plot_mandelbrot_thread, 
			scene->fractal_params[i]) != 0)
			log_perr("Something went wrong in thread creation.");
		i++;
	}
	i = 0;
	while (i < THREADS)
		pthread_join(threads[i++], NULL);
	plot_threaded_pixels(scene);
}