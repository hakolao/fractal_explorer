/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 18:54:27 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 14:14:26 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strrchr() function locates the last occurrence of c (converted to a
** char) in the string pointed to by s.  The terminating null character is
** considered to be part of the string; therefore if c is `\0',
** the functions locate the terminating `\0'.
*/

char	*ft_strrchr(const char *s, int c)
{
	char *ret;

	ret = NULL;
	while (*s)
	{
		if (*s == c)
			ret = (char*)s;
		s++;
	}
	if (*s == c)
		ret = (char*)s;
	return (ret);
}
