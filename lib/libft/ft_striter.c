/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:56:57 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 14:05:12 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Applies the function f to each character of the string passed
** as argument. Each character is passed by address to f to be
** modified if necessary.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	if (s && f)
		while (*s)
			f(&*(s++));
}
