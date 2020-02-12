/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:07:11 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/12 16:52:21 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <stdio.h>
# include <math.h>
# include <pthread.h>
# include "../lib/libft/libft.h"

/*
** Key codes for event listening
*/
# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_UP 126
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Q 12
# define KEY_E 14
# define KEY_P 35
# define KEY_1 18
# define KEY_2 19
# define KEY_NUM_4 86
# define KEY_NUM_6 88
# define KEY_NUM_8 91
# define KEY_NUM_2 84
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define MOUSE_BUTTON_RIGHT 2
# define MOUSE_BUTTON_LEFT 1
# define KEY_R 15
# define KEY_NUM_PLUS 69
# define KEY_NUM_MINUS 78
# define KEY_G 5
# define KEY_C 8
# define KEY_B 11
# define KEY_TAB 48
# define KEY_SHIFT 257
# define KEY_O 31

/*
** Color helpers
*/
# define CLAMP_0_255(color) (color > 255 ? 255 : color < 0 ? 0 : color)
# define ALPHA(a) ((a >> 24) & 255)
# define RED(r) ((r >> 16) & 255)
# define GREEN(g) ((g >> 8) & 255)
# define BLUE(b) (b & 255)
# define R(r) (CLAMP_0_255(r) & 255) << 16
# define G(g) (CLAMP_0_255(g) & 255) << 8
# define B(b) CLAMP_0_255(b) & 255
# define A(a) (CLAMP_0_255(a) & 255) << 24
# define COLOR(r, g, b, a) A(a) | R(r) | G(g) | B(b)
# define UI_COLOR COLOR(255, 255, 0, 255)
# define BACKGROUND_COLOR COLOR(0, 0, 0, 0)

/*
** Initial settings. (Choose Height that where
** HEIGHT % THREAD == 0)
*/
# define WIDTH 1080
# define HEIGHT 1080
# define MAX_WINDOWS 10
# define ASPECT_RATIO WIDTH / HEIGHT
# define MAX_ITER_INIT 30
# define COLORS 50
# define THREADS 8
# define PIXELS (WIDTH * HEIGHT) / THREADS
# define MANDEL_CENTER_X -0.7746806106269039
# define MANDEL_CENTER_Y -0.1374168856037867
# define JULIA_CENTER_X 0.0
# define JULIA_CENTER_Y 0.0

enum				e_fractal {
	mandelbrot,
	julia,
};

typedef struct		s_fractal_params
{
	t_pixel_bounds		*pixel_bounds;
	t_pixel				**pixels;
	int					size;
	int					max_iter;
	long double			zoom;
	int					*color_palette;
	long double			center_x;
	long double			center_y;
	long double			min_x;
	long double			max_x;
	long double			min_y;
	long double			max_y;
	long double			r;
	long double			cx;
	long double			cy;
	void				*frame;
	char				*frame_buf;
	int					width;
	int					height;
	int					thread_i;
	int					palette_size;
}					t_fractal_params;

/*
** Scene contains all data the application needs inside its loop
*/
typedef struct		s_scene
{
	int					id;
	void				*mlx;
	void				*mlx_wdw;
	int					pixel_bits;
	int					line_bytes;
	int					pixel_endian;
	int					mouse_left_pressed;
	int					mouse_x;
	int					mouse_y;
	int					stop_julia;
	int					show_guide;
	int					redraw;
	enum e_fractal		artist;
	t_rgb				**colors;
	int					palette_size;
	t_fractal_params	**fractal_params;
}					t_scene;

typedef struct		s_scenes
{
	int				size;
	void			*mlx;
	t_scene			**scenes;
}					t_scenes;

typedef	void		(*t_fractal_artist)(t_scene *scene);
typedef	int			(*t_fractal_param_f)(t_fractal_params *fractal_params,
					t_scene *scene, int thread_i);

/*
** Scene
*/
int					init_scene(t_scene *scene);
t_scene				*new_scene(void *mlx, enum e_fractal artist);

/*
** UI
*/
void				draw_paragraph(t_scene *scene, char *text, int xpos,
					int ypos);
void				draw_ui(t_scene *scene);
char				*guide(void);

/*
** Draw
*/
int					draw(t_scene *scene);
void				plot_pixel(t_scene *scene, int x, int y, int color);
int					lerp_rgb(int start, int end, double gradient_mul);
void				plot_threaded_pixels(t_scene *scene);
void				set_pixel(t_pixel *pixel, int x, int y, int color);
t_fractal_artist	artist_draw(enum e_fractal type);
void				plot_pixel_on_thread_frame(t_fractal_params *params,
					t_pixel *pixel);

/*
** Events
*/
int					handle_key_press(int key, void *param);
int					handle_key_release(int key, void *param);
int					handle_mouse_button_press(int key, int x, int y,
					void *param);
int					handle_mouse_button_release(int key, int x, int y,
					void *param);
int					handle_mouse_move(int x, int y, void *param);
int					handle_loop(void *params);
int					handle_exit_event(void *params);

/*
** Logging
*/
int					log_err(char *str, char *strerror);
int					log_perr(char *str);
int					log_guide(void);

/*
** Fractals
*/
void				draw_mandelbrot(t_scene *scene);
void				draw_julia(t_scene *scene);
int					zoom(t_scene *scene, long double amount);
int					mandelbrot_params(t_fractal_params
					*fractal_params, t_scene *scene, int i);
int					julia_params(t_fractal_params
					*fractal_params, t_scene *scene, int i);
int					move_by(t_scene *scene, long double x_amount,
					long double y_amount);
int					change_iters(t_scene *scene, long double amount);
long double			*scaled_xy(long double *x0_y0,
					t_fractal_params *params, int px, int py);
int					handle_julia_params(t_scene *scene, int mouse_x,
					int mouse_y);

/*
** Threads
*/
void				work_parallel(int num_threads, void **thread_params,
					void (*worker_f)(void *params));

/*
** Colors
*/
int					scene_colors(t_scene *scene);
int					color_palette(t_fractal_params *params,
					t_rgb **colors, int colors_size, int palette_size);
int					change_palette_size(t_scene *scene, int amount);
int					randomize_palette(t_scene *scene);

#endif
