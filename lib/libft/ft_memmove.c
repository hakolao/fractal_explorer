/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 14:25:18 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 13:43:29 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_memmove() function copies len bytes from string src to string dst.
** The two strings may overlap; the copy is always done in a non-destructive
** manner.
*/

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dstcopy;
	const char	*srccopy;
	const char	*last_src;
	char		*last_dst;

	if (src == NULL && dst == NULL)
		return (NULL);
	srccopy = src;
	dstcopy = dst;
	if (dstcopy < srccopy)
		ft_memcpy(dstcopy, srccopy, len);
	else
	{
		last_src = srccopy + (len - 1);
		last_dst = dstcopy + (len - 1);
		while (len--)
			*last_dst-- = *last_src--;
	}
	return (dst);
}
