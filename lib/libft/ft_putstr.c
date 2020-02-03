/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:54:27 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 13:52:06 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putstr_fd() writes a given string into stdout.
*/

void	ft_putstr(char const *str)
{
	int	len;

	if (!str)
		return ;
	len = ft_strlen(str);
	write(1, str, len);
}
