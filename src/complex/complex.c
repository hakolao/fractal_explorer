/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:16:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/18 17:42:27 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_complex			c_multiply(t_complex a, t_complex b)
{
	t_complex new;

	new.r = a.r * b.r - a.i * b.i;
	new.i = a.i * b.r + a.r * b.i;
	return (new);
}

t_complex			c_pow_int(t_complex c, int pow)
{
	int			i;
	t_complex	new;

	i = 0;
	new = (t_complex){1, 1};
	while (i < pow)
	{
		new = c_multiply(new, c);
		i++;
	}
	return (new);
}

t_complex			c_divide(t_complex a, t_complex b)
{
	t_complex	new;
	long double	divider;

	divider = (b.r * b.r + b.i * b.i);
	if (divider == 0.0)
		divider = 0.000001;
	new.r = (a.r * b.r + a.i * b.i) / divider;
	new.i = (a.i * b.r - a.r * b.i) / divider;
	return (new);
}

t_complex			c_add(t_complex a, t_complex b)
{
	t_complex	new;

	new.r = a.r + b.r;
	new.i = a.i + b.i;
	return (new);
}

t_complex			c_minus(t_complex a, t_complex b)
{
	t_complex	new;

	new.r = a.r - b.r;
	new.i = a.i - b.i;
	return (new);
}
