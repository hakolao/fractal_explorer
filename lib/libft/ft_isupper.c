/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 16:25:12 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 12:50:56 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_isupper() function tests for any character
** is within uppercase alphabet range
*/

int	ft_isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}
