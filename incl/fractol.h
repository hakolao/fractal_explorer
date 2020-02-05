/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:07:11 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/05 18:08:46 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

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
** Initial settings.
*/
# define WIDTH 1920
# define HEIGHT 1080
# define ASPECT_RATIO WIDTH / HEIGHT
# define MAX_ITER 1000
# define THREADS 8

typedef struct		s_fractal_params
{
	t_pixel_bounds		*pixel_bounds;
	t_thread_pixel		**pixels;
	int					size;
	int					max_iter;
}					t_fractal_params;

/*
** Scene contains all data the application needs inside its loop
*/
typedef struct		s_scene
{
	void				*mlx;
	void				*mlx_wdw;
	void				*frame;
	char				*frame_buf;
	int					pixel_bits;
	int					line_bytes;
	int					pixel_endian;
	int					mouse_right_pressed;
	int					mouse_left_pressed;
	int					shift_pressed;
	int					mouse_x;
	int					mouse_y;
	int					show_guide;
	int					redraw;
	int					col_r;
	int					col_g;
	int					col_b;
	int					col_a;
	int					max_iter;
	int					*color_palette;
	t_fractal_params	**fractal_params;
}					t_scene;

/*
** Scene
*/
int					init_scene(t_scene *scene);
t_scene				*new_scene(void *mlx, void *mlx_wdw);

/*
** UI
*/
void				draw_paragraph(t_scene *scene, char *text, int xpos,
					int ypos);
void				draw_ui(t_scene *scene);
char				*key_guide(t_scene *scene);
char				*mouse_guide(t_scene *scene);

/*
** Draw
*/
int					draw(t_scene *scene);
void				plot_pixel(t_scene *scene, int x, int y, int color);
int					lerp_rgb(int start, int end, double gradient_mul);

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
int					handle_exit_event(void);

/*
** Logging
*/
int					log_err(char *str, char *strerror);
int					log_perr(char *str);

/*
** Fractals
*/
void				draw_mandelbrot(t_scene *scene);

#endif
