/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_mul_vector_lst.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 14:24:25 by ohakola           #+#    #+#             */
/*   Updated: 2020/01/29 17:10:01 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

int		ft_matrix_mul_vector_lst(t_matrix *m, t_vector **vecs, size_t n)
{
	size_t		i;
	t_vector	vec;

	i = 0;
	while (i < n)
	{
		vec = (t_vector){.v = (double[4]){0, 0, 0, 0}, .size = 4};
		if (ft_matrix_mul_vector(m, vecs[i], &vec) == FALSE)
			return (0);
		vecs[i]->v[0] = vec.v[0];
		vecs[i]->v[1] = vec.v[1];
		vecs[i]->v[2] = vec.v[2];
		vecs[i]->v[3] = 1;
		i++;
	}
	return (1);
}
