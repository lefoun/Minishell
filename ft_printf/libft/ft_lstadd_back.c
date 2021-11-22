/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:44:43 by nammari           #+#    #+#             */
/*   Updated: 2021/03/23 18:44:45 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*elem;

	elem = *lst;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	while (elem->next)
	{
		elem = elem->next;
	}
	elem->next = new;
}
