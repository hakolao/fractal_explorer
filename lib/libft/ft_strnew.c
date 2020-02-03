/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:23:17 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/29 14:33:08 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Returns a new str of size `size`. Allocated with malloc().
*/

char	*ft_strnew(size_t size)
{
	char	*str;

	str = (char*)ft_memalloc(sizeof(*str) * size + 1);
	if (!str)
		return (NULL);
	return (str);
}
