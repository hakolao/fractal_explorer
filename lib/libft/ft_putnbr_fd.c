/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:45:46 by ohakola           #+#    #+#             */
/*   Updated: 2020/01/20 16:03:51 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** ft_putnbr_fd() writes a given integer into given file descriptor.
*/

void	ft_putnbr_fd(int nb, int fd)
{
	int	digits[10];
	int	index;
	int sign;

	index = 0;
	sign = nb >= 0 ? 1 : -1;
	if (nb == FALSE)
		ft_putchar_fd('0', fd);
	while (nb != 0)
	{
		digits[index] = nb % 10;
		nb = nb / 10;
		index++;
	}
	index++;
	if (sign < 0)
		ft_putchar_fd('-', fd);
	while (--index > 0)
		ft_putchar_fd(sign * digits[index - 1] + '0', fd);
}
