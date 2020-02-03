/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putmatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:41:16 by ohakola           #+#    #+#             */
/*   Updated: 2019/12/19 14:39:21 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

void	ft_putmatrix(t_matrix *mat)
{
	size_t c;
	size_t r;

	r = 0;
	if (!mat)
		return ;
	printf("Matrix, cols: %d rows: %d\n", (int)(mat->cols), (int)(mat->rows));
	while (r < mat->rows)
	{
		c = 0;
		while (c < mat->cols)
		{
			printf("%2f", (float)VALUE_AT(mat, r, c));
			if (c < mat->cols - 1)
				printf(" ");
			c++;
		}
		printf("\n");
		r++;
	}
}
