/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_view_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:56:22 by ohakola           #+#    #+#             */
/*   Updated: 2020/01/31 15:13:29 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

static int			view_matrix(t_local_axes *axes, t_vector *position,
					t_matrix *res)
{
	double		vals[16];

	vals[0] = axes->xaxis->v[0];
	vals[1] = axes->yaxis->v[0];
	vals[2] = axes->zaxis->v[0];
	vals[3] = 0;
	vals[4] = axes->xaxis->v[1];
	vals[5] = axes->yaxis->v[1];
	vals[6] = axes->zaxis->v[1];
	vals[7] = 0;
	vals[8] = axes->xaxis->v[2];
	vals[9] = axes->yaxis->v[2];
	vals[10] = axes->zaxis->v[2];
	vals[11] = 0;
	vals[12] = -ft_vector_dot(axes->xaxis, position);
	vals[13] = -ft_vector_dot(axes->yaxis, position);
	vals[14] = -ft_vector_dot(axes->zaxis, position);
	vals[15] = 1;
	return (ft_matrix_set_vals(res, vals, 16));
}

static int			ft_vector4_negate(t_vector *vec)
{
	vec->v[0] = -vec->v[0];
	vec->v[1] = -vec->v[1];
	vec->v[2] = -vec->v[2];
	return (0);
}

int					ft_fps_cam(t_vector *position, double pitch, double yaw,
					t_matrix *res)
{
	t_vector		zaxis;
	t_vector		xaxis;
	t_vector		yaxis;
	t_local_axes	xyz;

	pitch *= M_PI / 180;
	yaw *= M_PI / 180;
	zaxis = (t_vector){.v = (double[]){
		sin(yaw) * cos(pitch), -sin(pitch), cos(pitch) * cos(yaw), 0},
		.size = 4};
	xaxis = (t_vector){.v = (double[]){cos(yaw), 0, -sin(yaw), 0},
		.size = 4};
	yaxis = (t_vector){.v = (double[]){
		sin(yaw) * sin(pitch), cos(pitch), cos(yaw) * sin(pitch), 0},
		.size = 4};
	ft_vector4_negate(&zaxis);
	xyz = (t_local_axes){.xaxis = &xaxis, .yaxis = &yaxis, .zaxis = &zaxis};
	return (view_matrix(&xyz, position, res));
}
