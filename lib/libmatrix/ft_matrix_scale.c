/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_scale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 16:21:21 by ohakola           #+#    #+#             */
/*   Updated: 2019/12/22 16:23:44 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

int		ft_matrix_scale(t_matrix *mat, t_matrix *scale, t_matrix *res)
{
	if (!mat || !scale || !ft_dimensions_equal(mat, scale))
	{
		ft_puterror("Invalid input in ft_matrix_scale.\n");
		return (0);
	}
	return (ft_matrix_mul(mat, scale, res));
}
