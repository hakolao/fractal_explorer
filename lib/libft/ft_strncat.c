/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:32:06 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 14:10:38 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strcat() and ft_strncat() functions append a copy of the
** null-terminated string s2 to the end of the null-terminated string s1,
** then add a terminating `\0'.  The string s1 must have sufficient space to
** hold the result. The ft_strncat() function appends not more than n characters
** from s2, and then adds a terminating `\0'.
*/

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	char	*dstcpy;
	size_t	i;

	dstcpy = dst;
	i = 0;
	while (*dstcpy)
		dstcpy++;
	while (*src && i < n)
	{
		*dstcpy++ = *src++;
		i++;
	}
	*dstcpy = '\0';
	return (dst);
}
