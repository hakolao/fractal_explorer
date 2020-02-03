/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector4_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 16:34:43 by ohakola           #+#    #+#             */
/*   Updated: 2019/12/22 16:34:56 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

t_vector	*ft_vector4_new(double x, double y, double z)
{
	t_vector *new;

	if ((new = ft_vector_new(4)) == NULL)
		return (NULL);
	new->v[0] = x;
	new->v[1] = y;
	new->v[2] = z;
	new->v[3] = 1;
	return (new);
}
