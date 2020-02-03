/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 17:02:04 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 12:42:35 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_atoi() function converts the initial portion
** of the string pointed to by str to int representation.
*/

static int	is_clearable(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' ||
			c == '\v' || c == '\f' || c == '\r');
}

static int	is_skippable(char c)
{
	return (c == '-' || c == '+');
}

int			ft_atoi(const char *str)
{
	unsigned long long int	res;
	int						sign;
	int						i;

	sign = 1;
	res = 0;
	while (*str && is_clearable(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (is_skippable(*str))
		str++;
	i = 0;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
		i++;
	}
	if (i > 19 || res >= 9223372036854775808ULL)
		return (sign > 0 ? -1 : 0);
	return (res * sign);
}
