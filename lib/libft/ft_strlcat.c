/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:44:58 by ohakola           #+#    #+#             */
/*   Updated: 2020/01/20 16:03:51 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_strlcat() appends string src to the end of dst.  It will append at
** most dstsize - strlen(dst) - 1 characters.  It will then NUL-terminate,
** unless dstsize is 0 or the original dst string was longer than dstsize
** (in practice this should not happen as it means that either dstsize is
** incorrect or that dst is not a proper string).
** If the src and dst strings overlap, the behavior is undefined.
*/

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	char		*dst_cpy;
	const char	*src_cpy;
	size_t		n;
	size_t		dst_len;

	dst_cpy = dst;
	src_cpy = src;
	n = dstsize;
	while (n-- && *dst_cpy)
		dst_cpy++;
	dst_len = dst_cpy - dst;
	n = dstsize - dst_len;
	if (n == FALSE)
		return (dst_len + ft_strlen(src_cpy));
	while (*src_cpy)
	{
		if (n != 1)
		{
			*dst_cpy++ = *src_cpy;
			n--;
		}
		src_cpy++;
	}
	*dst_cpy = '\0';
	return (dst_len + (src_cpy - src));
}
