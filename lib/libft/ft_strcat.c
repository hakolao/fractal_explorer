/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:22:20 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 13:55:13 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** ft_strcat() append a copy of the null-terminated string s2 to the
** end of the null-terminated string s1, then add a terminating `\0'.
** The string s1 must have sufficient space to hold the result.
*/

char	*ft_strcat(char *dst, const char *src)
{
	char	*dstcpy;

	dstcpy = dst;
	while (*dstcpy)
		dstcpy++;
	while (*src)
	{
		*dstcpy = *src;
		dstcpy++;
		src++;
	}
	*dstcpy = '\0';
	return (dst);
}
