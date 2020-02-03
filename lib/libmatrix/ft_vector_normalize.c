/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_normalize.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 13:43:02 by ohakola           #+#    #+#             */
/*   Updated: 2020/01/16 13:49:17 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

int		ft_vector_normalize(t_vector *vec, t_vector *res)
{
	size_t		i;
	double		mag;

	if (!vec || !res || vec->size != res->size)
	{
		ft_puterror("Invalid input in ft_vector_normalize.\n");
		return (0);
	}
	i = 0;
	mag = ft_vector_mag(vec);
	while (i < vec->size)
	{
		res->v[i] = vec->v[i] / mag;
		i++;
	}
	return (1);
}
