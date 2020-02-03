/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:25:51 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 12:50:20 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_islower() function tests for any character
** is within lower alphabet ascii range
*/

int	ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
