/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:31:06 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 12:58:35 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_memalloc() allocates size of memory initialized with zeros
*/

void	*ft_memalloc(size_t size)
{
	unsigned char	*mem;

	mem = (void*)malloc(size);
	if (!mem)
		return (NULL);
	ft_bzero(mem, size);
	return ((void*)mem);
}
