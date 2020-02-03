/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 15:01:39 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 12:49:59 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_isdigit() function tests for any character
** is within ascii digit range '0' - '9' (48 - 57)
*/

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
