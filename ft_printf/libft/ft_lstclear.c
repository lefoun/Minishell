/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:45:01 by nammari           #+#    #+#             */
/*   Updated: 2021/05/28 14:24:34 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;
	t_list	*current;

	current = *lst;
	if (!lst || !del)
		return ;
	while (current)
	{
		tmp = current->next;
		(*del)(current->content);
		free(current);
		current = tmp;
	}
	(*lst) = NULL;
}
