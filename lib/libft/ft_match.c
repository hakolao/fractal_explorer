/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_match.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/20 16:04:36 by ohakola           #+#    #+#             */
/*   Updated: 2020/02/20 17:47:43 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_match(char *s1, char *s2)
{
	if (*s1 && *s2 == '*')
		return (ft_match(s1 + 1, s2) || ft_match(s1, s2 + 1));
	else if ((!*s1 && *s2 == '*'))
		return (ft_match(s1, s2 + 1));
	else if (*s1 == *s2 && *s1 && *s2)
		return (ft_match(s1 + 1, s2 + 1));
	else if (!*s1 && !*s2)
		return (1);
	return (0);
}
