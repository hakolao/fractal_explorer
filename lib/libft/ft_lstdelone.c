/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohakola <ohakola@student.helsinki.fi>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 15:57:08 by ohakola           #+#    #+#             */
/*   Updated: 2019/10/28 12:53:27 by ohakola          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_lstdelone() function deletes a one list element
** using a given delete function
*/

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if ((*alst)->content)
		del((*alst)->content, (*alst)->content_size);
	ft_memdel((void*)alst);
}
