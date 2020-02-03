/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotation_matrix.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 15:30:23 by ohakola           #+#    #+#             */
/*   Updated: 2020/01/31 16:22:19 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

static int			rotation_around_x(int amount, t_matrix *res)
{
	t_matrix	rotation;
	double		angle;

	angle = (M_PI / 180) * amount;
	rotation = (t_matrix){.m = (double[16]){0}, .cols = 4, .rows = 4};
	VALUE_AT(&rotation, 0, 0) = 1;
	VALUE_AT(&rotation, 3, 3) = 1;
	VALUE_AT(&rotation, 1, 1) = cos(angle);
	VALUE_AT(&rotation, 1, 2) = -sin(angle);
	VALUE_AT(&rotation, 2, 1) = sin(angle);
	VALUE_AT(&rotation, 2, 2) = cos(angle);
	return (ft_matrix_set_vals(res, rotation.m, 16));
}

static int			rotation_around_y(int amount, t_matrix *res)
{
	t_matrix	rotation;
	double		angle;

	angle = (M_PI / 180) * amount;
	rotation = (t_matrix){.m = (double[16]){0}, .cols = 4, .rows = 4};
	VALUE_AT(&rotation, 1, 1) = 1;
	VALUE_AT(&rotation, 3, 3) = 1;
	VALUE_AT(&rotation, 0, 0) = cos(angle);
	VALUE_AT(&rotation, 2, 0) = -sin(angle);
	VALUE_AT(&rotation, 0, 2) = sin(angle);
	VALUE_AT(&rotation, 2, 2) = cos(angle);
	return (ft_matrix_set_vals(res, rotation.m, 16));
}

static int			rotation_around_z(int amount, t_matrix *res)
{
	t_matrix	rotation;
	double		angle;

	angle = (M_PI / 180) * amount;
	rotation = (t_matrix){.m = (double[16]){0}, .cols = 4, .rows = 4};
	VALUE_AT(&rotation, 2, 2) = 1;
	VALUE_AT(&rotation, 3, 3) = 1;
	VALUE_AT(&rotation, 0, 0) = cos(angle);
	VALUE_AT(&rotation, 0, 1) = -sin(angle);
	VALUE_AT(&rotation, 1, 0) = sin(angle);
	VALUE_AT(&rotation, 1, 1) = cos(angle);
	return (ft_matrix_set_vals(res, rotation.m, 16));
}

int					ft_rotation_matrix(int angle_x, int angle_y, int angle_z,
					t_matrix *res)
{
	t_matrix	rotation_x;
	t_matrix	rotation_y;
	t_matrix	rotation_z;
	t_matrix	tmp;

	rotation_x = (t_matrix){.m = (double[16]){0}, .cols = 4, .rows = 4};
	rotation_y = (t_matrix){.m = (double[16]){0}, .cols = 4, .rows = 4};
	rotation_z = (t_matrix){.m = (double[16]){0}, .cols = 4, .rows = 4};
	tmp = (t_matrix){.m = (double[16]){0}, .cols = 4, .rows = 4};
	return (rotation_around_x(angle_x, &rotation_x) &&
		rotation_around_y(angle_y, &rotation_y) &&
		rotation_around_z(angle_z, &rotation_z) &&
		ft_matrix_mul(&rotation_y, &rotation_x, &tmp) &&
		ft_matrix_mul(&rotation_z, &tmp, res));
}
