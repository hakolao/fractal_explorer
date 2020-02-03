/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:43:00 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 12:50:40 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_isprint() function tests for any character
** is a printable character
*/

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
