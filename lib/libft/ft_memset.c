/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 13:47:36 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 13:43:26 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_memset() function writes len bytes of value c
** (converted to an unsigned char) to the string b.
*/

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *cpy;

	cpy = b;
	while (len--)
		*cpy++ = (unsigned char)c;
	return (b);
}
