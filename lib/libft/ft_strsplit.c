/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 20:51:20 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/29 14:32:28 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocates (with malloc(3)) and returns an array of “fresh”
** strings (all ending with ’\0’, including last array elem)
** obtained by spliting s using the character c as a delimiter.
** If the allocation fails the function returns NULL.
*/

static size_t		split_len(char *s, char c)
{
	char			*str;
	unsigned long	i;

	if (!*s)
		return (0);
	str = s;
	i = *str == c ? -1 : 0;
	while (*str)
	{
		if (*str == c)
		{
			while (*str == c)
				str++;
			if (*str)
				i++;
		}
		str++;
	}
	return (i + 1);
}

static size_t		word_len(char *str, char c)
{
	size_t i;

	i = 0;
	while (*str != c && *str)
	{
		i++;
		str++;
	}
	return (i);
}

char				**ft_strsplit(char const *str, char c)
{
	char			**arr;
	size_t			i;
	size_t			str_len;

	if (!str)
		return (NULL);
	if (!(arr = (char**)ft_memalloc(sizeof(char*) *
				(split_len((char*)str, c) + 1))))
		return (NULL);
	i = 0;
	while (*str)
	{
		while (*str == c && *str)
			str++;
		if (*str != c && *str)
		{
			str_len = word_len((char*)str, c);
			if (!(arr[i] = ft_strsub(str, 0, str_len)))
				return (NULL);
			str += str_len;
			i++;
		}
	}
	arr[i] = NULL;
	return (arr);
}
