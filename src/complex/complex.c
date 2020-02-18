/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 15:16:39 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/18 15:27:32 by ohakola          ###   ########.fr       */
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
	new = c;
	while (i < pow - 1)
	{
		new = c_multiply(new, c);
		i++;
	}
	return (new);
}

t_complex			c_divide(t_complex a, t_complex b)
{
	t_complex	new;

	new.r = (a.r * b.r + a.i * b.i) / (b.r * a.i + b.i * b.i);
    new.i = (a.i * b.r - a.r * b.i) / (b.r * b.r + b.i * b.i);
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