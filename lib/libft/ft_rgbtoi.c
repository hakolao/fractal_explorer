/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rgbtoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 13:06:36 by ohakola           #+#    #+#             */
/*   Updated: 2019/12/19 15:56:03 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Converts traditional R G B
** value to single integer form.
*/

#include "libft.h"

int		ft_rgbtoi(t_rgb rgb)
{
	return ((rgb.r & 255) << 16) | ((rgb.g & 255) << 8 | (rgb.b & 255));
}
