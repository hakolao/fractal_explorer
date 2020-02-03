/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:11:17 by ohakola           #+#    #+#             */
/*   Updated: 2020/01/20 16:03:51 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strcmp() and ft_strcmp() functions lexicographically
** compare the null-terminated strings s1 and s2.
*/

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == FALSE)
		return (0);
	while (n > 0)
	{
		if (*s1 != *s2)
			return ((*(unsigned char *)s1 < *(unsigned char *)s2) ? -1 : 1);
		if (!*s1)
			break ;
		s1++;
		s2++;
		n--;
	}
	return (0);
}
