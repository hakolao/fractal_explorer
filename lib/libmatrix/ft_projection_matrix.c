/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_projection_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:59:32 by ohakola           #+#    #+#             */
/*   Updated: 2020/01/31 15:57:15 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

int			ft_orthographic_matrix(t_canvas *c, t_matrix *res)
{
	t_matrix	m;

	if (!c)
		return (0);
	m = (t_matrix){.m = (double[16]){0}, .cols = 4, .rows = 4};
	VALUE_AT(&m, 0, 0) = 2 / c->width;
	VALUE_AT(&m, 1, 1) = 2 / c->height;
	VALUE_AT(&m, 2, 2) = 1 / (c->far - c->near);
	VALUE_AT(&m, 2, 3) = -c->near / (c->far - c->near);
	VALUE_AT(&m, 3, 3) = 1;
	return (ft_matrix_set_vals(res, m.m, 16));
}

int			ft_perspective_matrix(t_canvas *c, t_matrix *res)
{
	t_matrix	m;
	double		ar;
	double		angle;

	angle = c->angle * M_PI / 180;
	if (!c)
		return (0);
	m = (t_matrix){.m = (double[16]){0}, .cols = 4, .rows = 4};
	ar = c->width / c->height;
	VALUE_AT(&m, 0, 0) = 1 / (ar * tan(angle / 2));
	VALUE_AT(&m, 1, 1) = 1 / tan(angle / 2);
	VALUE_AT(&m, 2, 2) = (-c->near - c->far) / (c->near - c->far);
	VALUE_AT(&m, 3, 2) = 1;
	VALUE_AT(&m, 2, 3) = (2 * c->near * c->far) / (c->near - c->far);
	return (ft_matrix_set_vals(res, m.m, 16));
}
