/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:58:35 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 13:44:26 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	ft_putchar_fd() writes a character into given file descriptor
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
