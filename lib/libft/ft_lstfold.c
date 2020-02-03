/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfold.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 20:13:20 by ohakola           #+#    #+#             */
/*   Updated: 2019/11/18 18:52:45 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_lstfold() function iterates over all list elements
** applying a "summing / folding" function over all elements
** producing one output.
** E.g something like: [1,2,4].fold(0, (fold, content) -> fold + content) = 7.
*/

static void		*ft_lstfold_rec(void *fold,
				t_list *lst, void *(*f)(void*, void*))
{
	if (lst && f)
	{
		fold = ft_lstfold_rec(f(fold, lst->content), lst->next, f);
	}
	return (fold);
}

void			*ft_lstfold(t_list *lst, void *(*f)(void*, void*))
{
	if (!lst)
		return (NULL);
	return (ft_lstfold_rec(lst->content, lst, f));
}
