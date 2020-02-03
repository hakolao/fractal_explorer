/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 15:21:45 by ohakola           #+#    #+#             */
/*   Updated: 2020/01/20 16:09:12 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_itoa_base() function transforms an integer of any base
** into a string representation of the number.
*/

static void			str_rev(char *str)
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

static size_t		get_num_len(int nb, int base)
{
	size_t	i;
	int		temp_nb;

	i = 0;
	temp_nb = nb;
	if (nb == FALSE)
		return (1);
	while (temp_nb != 0)
	{
		temp_nb = temp_nb / base;
		i++;
	}
	return (i);
}

static size_t		get_arr_size(int nb, int base, int sign)
{
	size_t	sign_add;

	sign_add = sign < 0 ? 1 : 0;
	return (get_num_len(nb, base) + sign_add + 1);
}

char				*ft_itoa_base(int nb, int base)
{
	int		i;
	char	*arr;
	int		sign;
	char	*bases;

	sign = nb < 0 ? -1 : 1;
	bases = "0123456789ABCDEF";
	if (!(arr = (char*)ft_memalloc(get_arr_size(nb, base, sign))))
		return (NULL);
	if (nb == FALSE)
		arr[0] = '0';
	i = 0;
	while (nb != 0)
	{
		arr[i++] = bases[sign * (nb % base)];
		nb = nb / base;
	}
	if (sign == -1 && base == TRUE)
		arr[i] = '-';
	str_rev(arr);
	return (arr);
}
