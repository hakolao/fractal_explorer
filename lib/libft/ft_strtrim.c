/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:34:37 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 17:01:39 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns a copy of the string
** given as argument without whitespaces at the beginning or at
** the end of the string.
** If s has no whitespaces at the beginning or at the end,
** the function returns a copy of s.
** If the allocation fails the function returns NULL.
*/

static int	is_clearable(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' ||
			c == '\v' || c == '\f' || c == '\r');
}

char		*ft_strtrim(char const *s)
{
	size_t			start;
	size_t			end;
	size_t			substr_len;

	if (!s)
		return (NULL);
	if (*s == '\0')
		return (ft_strnew(0));
	start = 0;
	end = ft_strlen(s) - 1;
	while (is_clearable(s[start]) && s[start])
		start++;
	while (is_clearable(s[end]) && s[end] && end > start)
		end--;
	substr_len = end + 1 - start;
	return (ft_strsub(s, start, substr_len));
}
