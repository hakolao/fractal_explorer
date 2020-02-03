/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_set_vals.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:40:55 by ohakola           #+#    #+#             */
/*   Updated: 2019/12/22 16:27:28 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

int		ft_vector_set_vals(t_vector *vec, double *arr, size_t arr_size)
{
	size_t i;

	if (arr_size != vec->size)
	{
		ft_puterror("Invalid input in ft_vector_set_vals.\n");
		return (0);
	}
	i = 0;
	while (i < vec->size)
	{
		vec->v[i] = arr[i];
		i++;
	}
	return (1);
}
