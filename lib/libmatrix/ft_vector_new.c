/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:34:31 by ohakola           #+#    #+#             */
/*   Updated: 2019/12/22 16:16:53 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

t_vector	*ft_vector_new(size_t size)
{
	t_vector	*vec;
	size_t		i;

	if ((vec = (t_vector *)malloc(sizeof(*vec))) == NULL)
		return (NULL);
	vec->size = size;
	if ((vec->v = (double *)malloc(size * sizeof(double))) == NULL)
		return (NULL);
	i = 0;
	while (i < size)
		vec->v[i++] = 0;
	return (vec);
}
