/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 13:47:53 by ohakola           #+#    #+#             */
/*   Updated: 2019/12/18 18:10:19 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

t_matrix	*ft_matrix_new(size_t cols, size_t rows)
{
	t_matrix	*mat;
	int			len;

	if ((mat = (t_matrix *)malloc(sizeof(*mat))) == NULL)
		return (NULL);
	mat->cols = cols;
	mat->rows = rows;
	len = cols * rows;
	if ((mat->m = (double *)malloc(len * sizeof(double))) == NULL)
		return (NULL);
	ft_matrix_set_all(mat, 0);
	return (mat);
}
