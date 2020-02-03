/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dimensions_equal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:30:44 by ohakola           #+#    #+#             */
/*   Updated: 2019/12/17 15:26:42 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

int		ft_dimensions_equal(const t_matrix *m1, const t_matrix *m2)
{
	return ((m1->cols == m2->cols && m1->rows == m2->rows));
}
