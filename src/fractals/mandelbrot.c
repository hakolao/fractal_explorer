/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 10:46:22 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/06 13:58:35 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		plot_mandelbrot(int pixel_i, int px, int py, void *args)
{
	double				x;
	double				y;
	double				x0;
	double				y0;
	double				rsquare;
	double				isquare;
	double				zsquare;
	double				log_zn;
	double				iter;
	t_fractal_params	*params;
	int					color;

	params = (t_fractal_params*)args;
	x0 = ft_lmap_double((double)px,
		(double[2]){0, (double)WIDTH}, (double[2]){
			params->zoom_multiplier * (-2.5 + params->x_move), 
			params->zoom_multiplier * (1.0 + params->x_move)});
	y0 = ft_lmap_double((double)py,
		(double[2]){0, (double)HEIGHT},(double[2]){
			params->zoom_multiplier * (-1.0 + params->y_move), 
			params->zoom_multiplier * (1.0 + params->y_move)});
    x = 0.0;
    y = 0.0;
	rsquare = 0.0;
	isquare = 0.0;
	zsquare = 0.0;
    iter = 0.0;
	while (rsquare + isquare <= (1 << 16) && iter < (params->max_iter))
	{
		x = rsquare - isquare + x0;
		y = zsquare - rsquare - isquare + y0;
		rsquare = x * x;
		isquare = y * y;
		zsquare = (x + y) * (x + y);
		iter++;
	}
	if (iter < params->max_iter)
	{
		log_zn = log(rsquare + isquare) / 2.0;
		iter = iter + 1.0 - log(log_zn / log(2.0)) / log(2.0);
		color = lerp_rgb(params->color_palette[(int)floor(iter)],
		params->color_palette[(int)(floor(iter) + 1.0)], iter - floor(iter));	
	}
	else
		color = params->color_palette[(int)iter];
	params->pixels[pixel_i]->color = color;
	params->pixels[pixel_i]->x = px;
	params->pixels[pixel_i]->y = py;
}

static void		*plot_mandelbrot_thread(void *args)
{
	t_fractal_params *params;

	params = (t_fractal_params*)args;

	ft_pixel_foreach(params->pixel_bounds, args,
		plot_mandelbrot);
	return (NULL);
}

static void		plot_threaded_pixels(t_scene *scene)
{
	int				i;
	int				j;
	t_pixel			*pixel;

	i = 0;
	while (i < THREADS)
	{
		j = 0;
		while (j < scene->fractal_params[i]->size)
		{
			pixel = scene->fractal_params[i]->pixels[j];
			plot_pixel(scene, pixel->x, pixel->y, pixel->color);
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