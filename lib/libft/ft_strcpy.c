/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 16:37:15 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 14:00:10 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strcpy() function copies the string src to dst
** (including the terminating `\0' character.)
*/

char	*ft_strcpy(char *dst, const char *src)
{
	return (ft_memcpy(dst, src, (size_t)(ft_strlen(src) + 1)));
}
