/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 15:46:32 by ohakola           #+#    #+#             */
/*   Updated: 2020/01/29 14:30:40 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

void	ft_matrix_free(t_matrix *mat)
{
	if (!mat)
	{
		ft_puterror("Invalid input in ft_matrix_free\n.");
		return ;
	}
	free(mat->m);
	free(mat);
	mat = NULL;
}
