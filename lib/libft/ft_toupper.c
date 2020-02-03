/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:37:33 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 14:20:21 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_toupper() function converts a lower-case letter to the
** corresponding upper-case letter.
*/

int		ft_toupper(int c)
{
	if (ft_islower(c))
		c -= 32;
	return (c);
}
