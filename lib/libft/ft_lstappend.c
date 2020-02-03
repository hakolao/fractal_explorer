/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/28 15:19:45 by ohakola           #+#    #+#             */
/*   Updated: 2019/11/26 16:11:56 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_lstappend() function adds a new t_list element
** to the end of an existing list
*/

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list	*head;

	if (alst && new)
	{
		head = *alst;
		while ((*alst)->next)
			*alst = (*alst)->next;
		(*alst)->next = new;
		new->prev = (*alst);
		*alst = head;
	}
}
