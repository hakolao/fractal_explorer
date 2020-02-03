/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:40:30 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 14:19:55 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_tolower() function converts an upper-case letter to the
** corresponding lower-case letter.
*/

int		ft_tolower(int c)
{
	if (ft_isupper(c))
		c += 32;
	return (c);
}
