/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 19:10:25 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/13 14:58:44 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_itoa() function transforms an integer base 10
** into a string representation of the number
*/

void				ft_str_rev(char *str)
{
	int		i;
	int		len;
	char	temp;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		temp = str[i];
		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
		i++;
	}
}

static size_t		get_num_len(long int nb)
{
	size_t	i;

	i = 0;
	if (nb == FALSE)
		return (1);
	while (nb != 0 && i++ >= 0)
		nb = nb / 10;
	return (i);
}

char				*ft_itoa(int nb)
{
	int		i;
	char	*arr;
	int		sign;

	sign = nb < 0 ? -1 : 1;
	if (!(arr = (char*)ft_memalloc(get_num_len(nb) + (sign < 0 ? 1 : 0) + 1)))
		return (NULL);
	if (nb == FALSE)
		arr[0] = '0';
	i = 0;
	while (nb != 0)
	{
		arr[i++] = sign * (nb % 10) + 48;
		nb = nb / 10;
	}
	if (sign == -1)
		arr[i] = '-';
	ft_str_rev(arr);
	return (arr);
}

char				*ft_itoa_long(long int nb)
{
	int		i;
	char	*arr;
	int		sign;

	sign = nb < 0 ? -1 : 1;
	if (!(arr = (char*)ft_memalloc(get_num_len(nb) + (sign < 0 ? 1 : 0) + 1)))
		return (NULL);
	if (nb == FALSE)
		arr[0] = '0';
	i = 0;
	while (nb != 0)
	{
		arr[i++] = sign * (nb % 10) + 48;
		nb = nb / 10;
	}
	if (sign == -1)
		arr[i] = '-';
	ft_str_rev(arr);
	return (arr);
}
