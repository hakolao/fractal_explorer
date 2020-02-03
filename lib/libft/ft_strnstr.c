/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:25:13 by ohakola           #+#    #+#             */
/*   Updated: 2020/01/20 16:03:51 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strnstr() function locates the first occurrence of the
** null-terminated string needle in the string haystack, where not
** more than len characters are searched.
** Characters that appear after a `\0' character are not searched.
*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t slen)
{
	char	*src;
	char	*find;
	size_t	needle_len;

	src = (char *)haystack;
	find = (char *)needle;
	needle_len = ft_strlen(needle);
	if (needle_len == FALSE)
		return (char *)(src);
	if (needle_len > slen)
		return ((char *)NULL);
	while (slen >= needle_len && *src)
	{
		if (ft_strncmp(src, find, needle_len) == FALSE)
			return ((char *)src);
		src++;
		slen--;
	}
	return ((char *)NULL);
}
