/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_sub_double.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:43:15 by ohakola           #+#    #+#             */
/*   Updated: 2019/12/22 16:00:01 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

int		ft_matrix_sub_double(const t_matrix *m1, const double d, t_matrix *res)
{
	size_t r;
	size_t c;

	if (!m1 || !res || !ft_dimensions_equal(m1, res))
	{
		ft_puterror("Invalid input in ft_matrix_sub_double.\n");
		return (0);
	}
	r = 0;
	while (r < m1->rows)
	{
		c = 0;
		while (c < m1->cols)
		{
			VALUE_AT(res, r, c) = VALUE_AT(m1, r, c) - d;
			c++;
		}
		r++;
	}
	return (1);
}
