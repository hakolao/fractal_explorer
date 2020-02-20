/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:07:11 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/20 20:09:29 by ohakola          ###   ########.fr       */
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
# define MOUSE_BUTTON_MIDDLE 3
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
** HEIGHT % THREAD == 0).
** The screen has been split to horizontal
** slices (crucial to be aware if changes are
** planned)
*/
# define WIDTH 1080
# define HEIGHT 1080
# define MAX_WINDOWS 10
# define MAX_ITER_INIT 30
# define COLORS 50
# define THREADS 8
# define MANDEL_CENTER_X -0.7746806106269039
# define MANDEL_CENTER_Y -0.1374168856037867
# define JULIA_CENTER_X 0.0
# define JULIA_CENTER_Y 0.0
# define BURNING_CENTER_X 0.0
# define BURNING_CENTER_Y 0.0

/*
** Image Render
*/
# define IMG_WIDTH 4096
# define IMG_HEIGHT 4096
# define FILE_HEADER_SIZE 14
# define INFO_HEADER_SIZE 40
# define BYTES_PER_PIXEL 4

enum				e_fractal {
	mandelbrot,
	julia,
	burning_ship,
	mandelbrot_n,
	julia_n,
	bird_of_prey,
	julia_mod,
	phoenix_mod,
	burning_julia
};

typedef struct		s_complex
{
	long double		r;
	long double		i;
}					t_complex;

typedef struct s_fractal_params	t_fractal_params;

typedef long double	(*t_escape_time)(t_complex z,
							t_complex c, t_complex *squares,
							t_fractal_params *params);

struct				s_fractal_params
{
	t_pixel_bounds		*pixel_bounds;
	t_pixel				**pixels;
	int					size;
	int					max_iter;
	long double			zoom;
	int					*palette;
	long double			center_x;
	long double			center_y;
	long double			min_x;
	long double			max_x;
	long double			min_y;
	long double			max_y;
	long double			r;
	long double			cx;
	long double			cy;
	long double			px;
	long double			py;
	int					cx_sign;
	int					cy_sign;
	long double			pow_n;
	void				*frame;
	char				*frame_buf;
	int					width;
	int					height;
	int					thread_i;
	int					palette_size;
	t_escape_time		escape_time;
};

/*
** Scene contains all data the application needs inside its loop
*/
typedef struct s_scenes	t_scenes;

typedef struct		s_scene
{
	int					id;
	void				*mlx;
	void				*mlx_wdw;
	void				*screenshot;
	char				*screenshot_buf;
	int					screen_width;
	int					screen_height;
	int					pixel_bits;
	int					line_bytes;
	int					pixel_endian;
	int					mouse_left_pressed;
	int					stop_julia;
	int					show_guide;
	int					stop_phoenix_mod;
	int					redraw;
	enum e_fractal		artist;
	t_rgb				**colors;
	int					colors_size;
	int					palette_size;
	t_fractal_params	**fractal_params;
	t_scenes			*data;
}					t_scene;

typedef struct		s_colors
{
	t_rgb			**colors;
	int				size;
}					t_colors;

struct				s_scenes
{
	int				size;
	void			*mlx;
	t_colors		*color_data;
	t_scene			**scenes;
};

typedef	void		(*t_fractal_artist)(t_scene *scene);
typedef	int			(*t_fractal_param_f)(t_fractal_params *fractal_params,
					t_scene *scene, int thread_i);

/*
** Args
*/
int					check_args(char *arg, int *size, int *fractal);
t_colors			*parse_colors(char *arg);

/*
** Scene
*/
int					init_scene(t_scene *scene);
t_scene				*new_scene(t_scenes *data, enum e_fractal artist,
					int width, int height);
void				delete_scene(t_scene *scene);
t_scene				*image_render_scene(t_scene *scene);

/*
** UI
*/
void				draw_paragraph(t_scene *scene, char *text, int xpos,
					int ypos);
void				draw_ui(t_scene *scene);
char				*guide(void);
void				draw_cx_cy_sign_info(t_scene *scene, int x, int y);
void				draw_power_info(t_scene *scene, int x, int y);
void				draw_cx_cy_info(t_scene *scene, int x, int y);
void				draw_px_py_info(t_scene *scene, int x, int y);

/*
** Draw
*/
int					draw(t_scene *scene);
void				plot_pixel(t_scene *scene, int x, int y, int color);
int					lerp_rgb(int start, int end, double gradient_mul);
void				plot_threaded_pixels(t_scene *scene);
void				set_pixel(t_pixel *pixel, int x, int y, int color);
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
void				julia_pixel(int pixel_i, int px,
					int py, void *args);
void				mandelbrot_pixel(int pixel_i, int px,
					int py, void *args);
void				draw_mandelbrot(t_scene *scene);
void				draw_julia(t_scene *scene);
int					mandelbrot_params(t_fractal_params
					*fractal_params, t_scene *scene, int i);
int					mandelbrot_n_params(t_fractal_params
					*fractal_params, t_scene *scene, int i);
int					julia_n_params(t_fractal_params
					*fractal_params, t_scene *scene, int i);
int					julia_params(t_fractal_params
					*fractal_params, t_scene *scene, int i);
int					burning_ship_params(t_fractal_params
					*fractal_params, t_scene *scene, int i);
int					bird_of_prey_params(t_fractal_params
					*fractal_params, t_scene *scene, int i);
int					julia_mod_params(t_fractal_params
					*fractal_params, t_scene *scene, int i);
int					phoenix_mod_params(t_fractal_params
					*fractal_params, t_scene *scene, int i);
int					burning_julia_params(t_fractal_params
					*fractal_params, t_scene *scene, int i);
long double			mandelbrot_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params);
long double			multibrot_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params);
long double			julia_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params);
long double			julia_n_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params);
long double			julia_mod_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params);
long double			burning_ship_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params);
long double			bird_of_prey_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params);
long double			phoenix_mod_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params);
long double			burning_julia_escape(t_complex z, t_complex c,
					t_complex *squares, t_fractal_params *params);

/*
** Fractal utils (functionality)
*/

int					zoom(t_scene *scene, long double amount);
int					move_by(t_scene *scene, long double x_amount,
					long double y_amount);
int					change_iters(t_scene *scene, long double amount);
t_complex			scaled_xy(t_complex c,
					t_fractal_params *params, int px, int py);
int					move_cx_cy(t_scene *scene, int mouse_x,
					int mouse_y);
int					center_to(t_scene *scene, long double mouse_x,
					long double mouse_y);
int					increment_pow_n(t_scene *scene, int incr);
void				smooth_color_pixel(t_pixel *pixel, long double iter,
					t_complex squares, t_fractal_params *params);
int					flip_cy_sign(t_scene *scene);
int					flip_cx_sign(t_scene *scene);
int					move_px_py(t_scene *scene, int mouse_x,
					int mouse_y);
int					save_image(t_scene *scene);
void				copy_scene_fractal_positions(t_fractal_params **dst,
					t_fractal_params **src);

/*
** Threads
*/
void				work_parallel(int num_threads, void **thread_params,
					void (*worker_f)(void *params));
t_fractal_params	**thread_fractal_params(t_scene *scene);
int					thread_render_params(t_fractal_params
					*fractal_params, t_scene *scene, int i);

/*
** Colors
*/
t_colors			*default_colors(void);
int					color_palette(t_fractal_params *params,
					t_rgb **colors, int colors_size, int palette_size);
int					change_palette_size(t_scene *scene, int amount);
int					randomize_palette(t_scene *scene);

/*
** Selectors
*/
t_fractal_artist	artist_draw(enum e_fractal type);
t_fractal_param_f	select_params(enum e_fractal type);
char				*artist_name(enum e_fractal artist);

/*
** Complex number functions
*/
t_complex			c_multiply(t_complex a, t_complex b);
t_complex			c_pow_int(t_complex c, int pow);
t_complex			c_divide(t_complex a, t_complex b);
t_complex			c_add(t_complex a, t_complex b);
t_complex			c_minus(t_complex a, t_complex b);

#endif
