/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 13:12:04 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 13:45:21 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putendl_fd() writes a string into stdout followed by a
** newline.
*/

void	ft_putendl(char const *s)
{
	if (!s)
		return ;
	ft_putstr(s);
	ft_putchar('\n');
}
