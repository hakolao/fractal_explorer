/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_sub.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 14:18:04 by ohakola           #+#    #+#             */
/*   Updated: 2020/01/16 13:33:56 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

int		ft_vector_sub(t_vector *v1, t_vector *v2, t_vector *res)
{
	size_t		i;

	if (!v1 || !v2 ||
		!(v1->size == v2->size) ||
		!(v1->size == res->size))
	{
		ft_puterror("Invalid input in ft_vector_sub.\n");
		return (0);
	}
	i = 0;
	while (i < v1->size)
	{
		res->v[i] = v1->v[i] - v2->v[i];
		i++;
	}
	return (1);
}
