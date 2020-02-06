/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 13:59:45 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/06 12:43:57 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int				init_fractol()
{
	t_scene		*scene;
	void		*mlx;
	void		*mlx_wdw;

	if (((mlx = mlx_init()) == NULL ||
		(mlx_wdw = mlx_new_window(mlx, WIDTH, HEIGHT,
		"Fractol - ohakola")) == NULL ||
		(scene = new_scene(mlx, mlx_wdw)) == NULL) &&
			log_err("Failed to create scene.", strerror(5)))
		return (0);
	mlx_hook(mlx_wdw, 2, 0, handle_key_press, scene);
	mlx_hook(mlx_wdw, 3, 0, handle_key_release, scene);
	mlx_hook(mlx_wdw, 4, 0, handle_mouse_button_press, scene);
	mlx_hook(mlx_wdw, 5, 0, handle_mouse_button_release, scene);
	mlx_hook(mlx_wdw, 6, 0, handle_mouse_move, scene);
	mlx_hook(mlx_wdw, 17, 0, handle_exit_event, scene);
	mlx_loop_hook(mlx, handle_loop, scene);
	mlx_loop(mlx);
	return (0);
}

int				main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	init_fractol();
	return (0);
}
