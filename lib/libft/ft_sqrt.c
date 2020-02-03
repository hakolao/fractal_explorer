/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 17:32:45 by ohakola           #+#    #+#             */
/*   Updated: 2019/11/22 14:10:35 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Ref:
** https://www.codeproject.com/Articles/69941/
** Best-Square-Root-Method-Algorithm-Function-Precisi
*/

float	ft_sqrt(const float x)
{
	int		i;
	float	d;
	float	p;
	float	a;

	i = 0;
	while ((i * i) <= x)
		i++;
	i--;
	d = x - i * i;
	p = d / (2 * i);
	a = i + p;
	return (a - (p * p) / (2 * a));
}
