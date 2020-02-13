/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 13:19:03 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/13 14:31:50 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_num_len(long int nb)
{
	int	i;

	i = 0;
	if (nb == FALSE)
		return (1);
	while (nb != 0 && i++ >= 0)
		nb = nb / 10;
	return (i);
}

static char		*add_zeros(long int fpart, int precision, char *str)
{
	int		i;
	int		j;
	int		len;
	int		zeros;
	char	*res;

	len = get_num_len(fpart);
	zeros = precision - len;
	if (zeros <= 0)
		return (str);
	if (!(res = ft_strnew(ft_strlen(str) + zeros)))
		return (NULL);
	res = ft_strcpy(res, str);
	i = ft_strlen(str);
	j = 0;
	while (j < zeros)
	{
		res[i] = '0';
		j++;
		i++;
	}
	ft_strdel(&str);
	return (res);
}

char			*ft_ftoa(float nb, int precision)
{
	int		ipart;
	float	fpart;
	char	*result;
	char	*tmp1;
	char	*tmp2;

	ipart = (int)nb;
	fpart = ft_abs_long_double(nb) - ft_abs_long_double((float)ipart);
	if (!(tmp1 = ft_itoa_long(ipart)))
		return (NULL);
	if (precision <= 0)
		return (tmp1);
	if (!(result = ft_strjoin(tmp1, ".")))
		return (NULL);
	ft_strdel(&tmp1);
	fpart = fpart * ft_pow(10, precision);
	if (!(result = add_zeros(fpart, precision, result)))
		return (NULL);
	if (!(tmp2 = ft_itoa_long(fpart)))
		return (NULL);
	if (!(tmp1 = ft_strjoin(result, tmp2)))
		return (NULL);
	ft_strdel(&result);
	result = tmp1;
	return (result);
}
