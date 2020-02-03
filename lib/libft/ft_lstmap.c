/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:18:34 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 12:57:10 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_lstmap() function iterates over all list elements
** applying a function f on each element producing a new list.
*/

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list*))
{
	t_list	*node;

	if (lst)
	{
		node = f(lst);
		node->next = ft_lstmap(lst->next, f);
		return (node);
	}
	return (NULL);
}
