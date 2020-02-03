/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_set_all.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:38:34 by ohakola           #+#    #+#             */
/*   Updated: 2019/12/22 16:25:17 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

int		ft_vector_set_all(t_vector *vec, double d)
{
	size_t i;

	if (!vec)
	{
		ft_puterror("Invalid input in ft_vector_set_all.\n");
		return (0);
	}
	i = 0;
	while (i < vec->size)
		vec->v[i++] = d;
	return (1);
}
