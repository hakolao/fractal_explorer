/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_mul_vector.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:28:43 by ohakola           #+#    #+#             */
/*   Updated: 2020/01/16 16:23:22 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

int		ft_matrix_mul_vector(const t_matrix *m1, const t_vector *v,
		t_vector *res)
{
	size_t		r;
	size_t		c;

	if (m1->cols != v->size || v->size != res->size)
	{
		ft_puterror("Invalid input in ft_matrix_mul_vector\n");
		return (0);
	}
	r = 0;
	while (r < m1->rows)
	{
		c = 0;
		while (c < m1->cols)
		{
			res->v[r] += VALUE_AT(m1, r, c) * v->v[c];
			c++;
		}
		r++;
	}
	return (1);
}
