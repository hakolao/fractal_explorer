/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:44:07 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/12 16:49:49 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_sort_int_tab(int *tab, unsigned int size, int dir)
{
	unsigned int	i;
	int				tmp;

	i = 0;
	while (i < size - 1)
	{
		if ((dir > 0 && tab[i] > tab[i + 1]) ||
			(dir < 0 && tab[i] < tab[i + 1]))
		{
			tmp = tab[i];
			tab[i] = tab[i + 1];
			tab[i + 1] = tmp;
			i = 0;
		}
		else
			i++;
	}
}
