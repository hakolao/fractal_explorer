/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_mul.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 16:09:19 by ohakola           #+#    #+#             */
/*   Updated: 2020/01/21 18:07:01 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

int		ft_matrix_mul(const t_matrix *m1, const t_matrix *m2,
		t_matrix *res)
{
	size_t		r;
	size_t		c;
	size_t		i;

	if (!(m1->cols == m2->rows || m1->rows == m2->cols) ||
		!(res->rows == m1->rows && res->cols == m2->cols))
	{
		ft_puterror("Invalid input in ft_matrix_mul.\n");
		return (0);
	}
	r = 0;
	while (r < m1->rows)
	{
		c = 0;
		while (c < m2->cols)
		{
			VALUE_AT(res, r, c) = 0;
			i = -1;
			while (++i < m1->cols)
				VALUE_AT(res, r, c) += VALUE_AT(m1, r, i) * VALUE_AT(m2, i, c);
			c++;
		}
		r++;
	}
	return (1);
}
