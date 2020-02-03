/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:21:09 by ohakola           #+#    #+#             */
/*   Updated: 2019/12/22 16:06:45 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

int		ft_vector_add(t_vector *v1, t_vector *v2, t_vector *res)
{
	size_t		i;

	if (!v1 || !v2 ||
		!(v1->size == v2->size && v1->size == res->size))
	{
		ft_puterror("Invalid input in ft_vector_add.\n");
		return (0);
	}
	i = 0;
	while (i < v1->size)
	{
		res->v[i] = v1->v[i] + v2->v[i];
		i++;
	}
	return (1);
}
