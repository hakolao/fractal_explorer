/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:33:56 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 13:41:18 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_memcpy() function copies n bytes from memory area src to memory
** area dst.
** If dst and src overlap, behavior is undefined.  Applications in
** which dst and src might overlap should use memmove(3) instead.
*/

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*destcpy;
	const char	*srccpy;

	if (src == NULL && dst == NULL)
		return (NULL);
	destcpy = dst;
	srccpy = src;
	while (n--)
		*destcpy++ = *srccpy++;
	return (dst);
}
