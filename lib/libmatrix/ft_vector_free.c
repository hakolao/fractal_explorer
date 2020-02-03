/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 17:59:53 by ohakola           #+#    #+#             */
/*   Updated: 2020/01/29 14:30:31 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

void	ft_vector_free(t_vector *vec)
{
	if (!vec)
	{
		ft_puterror("Invalid input in ft_vector_free\n.");
		return ;
	}
	free(vec->v);
	free(vec);
	vec = NULL;
}
