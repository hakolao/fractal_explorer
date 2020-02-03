/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:56:04 by ohakola           #+#    #+#             */
/*   Updated: 2020/01/20 16:03:51 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_bzero() function writes n zeroed bytes to the string s.
** If n is zero, bzero() does nothing.
*/

void	ft_bzero(void *s, size_t n)
{
	char	*cpy;

	if (n == FALSE)
		return ;
	cpy = s;
	while (n--)
		*cpy++ = 0;
}
