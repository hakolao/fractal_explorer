/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lmap_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 15:33:46 by ohakola           #+#    #+#             */
/*   Updated: 2020/01/28 16:28:12 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Linearly maps number from input scale to output scale
*/

double		ft_lmap_double(double nb, double *in_minmax, double *out_minmax)
{
	return ((nb - in_minmax[0]) *
			(out_minmax[1] - out_minmax[0]) /
			(in_minmax[1] - in_minmax[0]) +
			out_minmax[0]);
}
