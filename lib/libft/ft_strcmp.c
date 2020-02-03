/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:08:21 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 13:59:11 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strcmp() and ft_strcmp() functions lexicographically
** compare the null-terminated strings s1 and s2.
*/

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	if (!*s1 && !*s2)
		return (0);
	else if (*s1 && !*s2)
		return (1);
	return ((unsigned char)*s1 < (unsigned char)*s2 ? -1 : 1);
}
