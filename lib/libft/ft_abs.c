/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/08 12:55:05 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/13 12:55:55 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double		ft_abs(double nb)
{
	return (nb >= 0 ? nb : -nb);
}

long double	ft_abs_long_double(long double nb)
{
	return (nb >= 0 ? nb : -nb);
}
