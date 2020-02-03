/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_to_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:43:33 by ohakola           #+#    #+#             */
/*   Updated: 2019/12/22 16:32:15 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

int		ft_vector_to_matrix(const t_vector *vec, t_matrix *res)
{
	if (vec->size != res->rows || res->cols != 1)
	{
		ft_puterror("Invalid input in ft_vector_to_matrix.\n");
		return (0);
	}
	ft_matrix_set_vals(res, vec->v, vec->size);
	return (1);
}
