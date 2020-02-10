/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 17:20:06 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/10 12:08:32 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		color_fractal_pixel(t_pixel *pixel, double iter,
				double r_i_z_square[3], int *color_palette)
{
	double				log_zn;

	log_zn = log(r_i_z_square[0] + r_i_z_square[1]) / 2.0;
	iter = iter + 1.0 - log(log_zn / log(2.0)) / log(2.0);
	pixel->color = lerp_rgb(color_palette[(int)floor(iter) % COLORS],
		color_palette[(int)((floor(iter)) + 1) % COLORS],
		iter - floor(iter));
}

/*
** Centers of interest:
** http://paulbourke.net/fractals/mandelbrot/
*/

static double	*scaled_xy(double *x0_y0, t_fractal_params *params,
				int px, int py)
{
	double	min_x0;
	double	min_y0;
	double	max_x0;
	double	max_y0;

	min_x0 = params->min_x;
	max_x0 = params->max_y;
	min_y0 = params->min_y;
	max_y0 = params->max_y;
	x0_y0[0] = (min_x0 + px * (max_x0 - min_x0) / WIDTH) *
		params->zoom_mul + params->center_x;
	x0_y0[1] = (min_y0 + py * (max_y0 - min_y0) / HEIGHT) *
		params->zoom_mul + params->center_y;
	return (x0_y0);
}

static void		mandelbrot_pixel(int pixel_i, int px, int py, void *args)
{
	double				xy[2];
	double				*x0_y0;
	double				*r_i_z_square;
	double				iter;
	t_fractal_params	*params;

	params = (t_fractal_params*)args;
	r_i_z_square = (double[3]){0.0};
	x0_y0 = scaled_xy((double[2]){0.0}, params, px, py);
	iter = 0.0;
	while (r_i_z_square[0] + r_i_z_square[1] <= (1 << 2) &&
		iter < (params->max_iter))
	{
		xy[0] = r_i_z_square[0] - r_i_z_square[1] + x0_y0[0];
		xy[1] = r_i_z_square[2] - r_i_z_square[0] - r_i_z_square[1] + x0_y0[1];
		r_i_z_square[0] = xy[0] * xy[0];
		r_i_z_square[1] = xy[1] * xy[1];
		r_i_z_square[2] = (xy[0] + xy[1]) * (xy[0] + xy[1]);
		iter++;
	}
	set_pixel(params->pixels[pixel_i], px, py, COLOR(0, 0, 0, 0));
	if (iter < params->max_iter)
		color_fractal_pixel(params->pixels[pixel_i], iter, r_i_z_square,
			params->color_palette);
}

static void		mandelbrot_work(void *args)
{
	t_fractal_params *params;

	params = (t_fractal_params*)args;
	ft_pixel_foreach(params->pixel_bounds, args, mandelbrot_pixel);
}

void			draw_mandelbrot(t_scene *scene)
{
	work_parallel(THREADS, (void**)scene->fractal_params, mandelbrot_work);
	plot_threaded_pixels(scene);
}
