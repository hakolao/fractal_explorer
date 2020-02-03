/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 13:14:46 by ohakola           #+#    #+#             */
/*   Updated: 2020/01/29 13:16:44 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

t_vector	*ft_vector_dup(t_vector *v)
{
	t_vector	*new;
	size_t		i;

	if ((new = ft_vector_new(v->size)) == NULL)
		return (NULL);
	i = 0;
	while (i < v->size)
	{
		new->v[i] = v->v[i];
		i++;
	}
	return (new);
}
