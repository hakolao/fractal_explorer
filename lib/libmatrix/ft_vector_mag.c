/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_mag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:06:39 by ohakola           #+#    #+#             */
/*   Updated: 2019/12/18 17:15:42 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

double	ft_vector_mag(t_vector *vec)
{
	size_t		i;
	double		res;

	i = 0;
	res = 0;
	while (i < vec->size)
	{
		res += vec->v[i] * vec->v[i];
		i++;
	}
	return (sqrt(res));
}
