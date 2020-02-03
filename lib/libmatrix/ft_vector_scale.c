/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_scale.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 18:27:38 by ohakola           #+#    #+#             */
/*   Updated: 2019/12/22 16:21:07 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

int		ft_vector_scale(t_vector *vec, t_vector *scale)
{
	size_t i;

	if (!vec || !scale || vec->size != scale->size)
	{
		ft_puterror("Invalid input in ft_vector_scale\n.");
		return (0);
	}
	i = 0;
	while (i < vec->size)
	{
		vec->v[i] *= scale->v[i];
		i++;
	}
	return (1);
}
