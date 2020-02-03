/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 14:36:57 by ohakola           #+#    #+#             */
/*   Updated: 2019/12/22 16:03:35 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmatrix.h"

/*
** ft_putstr() writes a given string into stdout.
*/

void	ft_putstr(char const *str)
{
	int len;

	if (!str)
		return ;
	len = ft_strlen(str);
	write(1, str, len);
}
