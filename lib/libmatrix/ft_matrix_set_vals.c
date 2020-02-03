/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_set_vals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:03:48 by ohakola           #+#    #+#             */
/*   Updated: 2019/12/22 16:26:41 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

int		ft_matrix_set_vals(t_matrix *mat, double *arr, size_t arr_size)
{
	size_t	r;
	size_t	c;
	size_t	len;

	len = mat->cols * mat->rows;
	if (arr_size != len || !mat || !arr)
	{
		ft_puterror("Invalid input in ft_matrix_set_vals.\n");
		return (0);
	}
	r = 0;
	while (r < mat->rows)
	{
		c = 0;
		while (c < mat->cols)
		{
			VALUE_AT(mat, r, c) = arr[c * (mat)->rows + r];
			c++;
		}
		r++;
	}
	return (1);
}
