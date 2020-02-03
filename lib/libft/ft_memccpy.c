/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:11:16 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 13:00:11 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_memccpy() function copies bytes from string src to string dst.
** If the character c (as converted to an unsigned char) occurs in the
** string src, the copy stops and a pointer to the byte after the copy
** of c in the string dst is returned.  Otherwise, n bytes are copied,
** and a NULL pointer is returned.
*/

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char		*destcpy;
	const char	*srccpy;

	if (src == NULL && dst == NULL)
		return (NULL);
	destcpy = dst;
	srccpy = src;
	while (n--)
	{
		*destcpy = *srccpy;
		if ((unsigned char)*srccpy == (unsigned char)c)
			return (destcpy + 1);
		destcpy++;
		srccpy++;
	}
	return (NULL);
}
