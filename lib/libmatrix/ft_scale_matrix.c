/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scale_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:28:17 by ohakola           #+#    #+#             */
/*   Updated: 2020/01/31 16:28:44 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

int			ft_scale_matrix(size_t cols, size_t rows, t_vector *scale,
			t_matrix *res)
{
	size_t		r;
	size_t		c;

	if (cols != rows || scale->size != rows)
	{
		ft_puterror("Invalid input in ft_matrix_scale.\n");
		return (0);
	}
	r = 0;
	while (r < rows)
	{
		c = 0;
		while (c < cols)
		{
			VALUE_AT(res, r, c) = scale->v[r];
			r++;
			c++;
		}
		r++;
	}
	return (1);
}

t_matrix	*ft_scale_matrix_xyz(double x, double y, double z)
{
	t_matrix	*scale;

	if ((scale = ft_matrix_id(4, 4)) == NULL)
		return (NULL);
	VALUE_AT(scale, 0, 0) = x;
	VALUE_AT(scale, 1, 1) = y;
	VALUE_AT(scale, 2, 2) = z;
	return (scale);
}
