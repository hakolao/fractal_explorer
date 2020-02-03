/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:48:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/02 17:02:02 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_max_double(double *arr, size_t size)
{
	size_t	i;
	double	max;

	i = 0;
	max = arr[i];
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

int		ft_max_int(int *arr, size_t size)
{
	size_t	i;
	int		max;

	i = 0;
	max = arr[i];
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

double	ft_min_double(double *arr, size_t size)
{
	size_t	i;
	double	min;

	i = 0;
	min = arr[i];
	while (i < size)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}

int		ft_min_int(int *arr, size_t size)
{
	size_t	i;
	int		min;

	i = 0;
	min = arr[i];
	while (i < size)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return (min);
}
