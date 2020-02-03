/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:48:48 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 12:49:13 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_isascii() function tests for any character
** is within ascii range 0 and 127 including.
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
