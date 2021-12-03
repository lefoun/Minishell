/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 10:28:27 by sdummett          #+#    #+#             */
/*   Updated: 2021/03/23 16:16:25 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin_new_lst;
	t_list	*new_elem;

	begin_new_lst = 0;
	if (lst)
	{
		while (lst)
		{
			new_elem = ft_lstnew((*f)(lst->content));
			if (!new_elem)
			{
				ft_lstclear(&begin_new_lst, del);
				return (0);
			}
			ft_lstadd_back(&begin_new_lst, new_elem);
			lst = lst->next;
		}
	}
	return (begin_new_lst);
}
