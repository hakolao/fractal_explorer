/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:14:58 by ohakola           #+#    #+#             */
/*   Updated: 2019/11/17 21:59:19 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_lstiter() function iterates over all list elements
** applying a function f on each element.
*/

void	ft_lstiter(t_list *lst, void (*f)(t_list*))
{
	if (lst && f)
	{
		f(lst);
		ft_lstiter(lst->next, f);
	}
}
