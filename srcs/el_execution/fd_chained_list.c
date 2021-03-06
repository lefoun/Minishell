/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_chained_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:50:55 by nammari           #+#    #+#             */
/*   Updated: 2021/12/06 13:24:41 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"

int	elem_pushback(t_fd_chain **head, t_fd_chain *elem)
{
	t_fd_chain	*tmp;

	if (head == NULL || elem == NULL)
		return (-1);
	else if (*head == NULL)
		*head = elem;
	else
	{
		tmp = *head;
		while (tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = elem;
	}
	return (0);
}

t_fd_chain	*create_elem(int fd, char *file_name)
{
	t_fd_chain	*new;

	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		error_malloc();
		return (NULL);
	}
	new->file_name = ft_strdup(file_name);
	new->fd = fd;
	new->next = NULL;
	return (new);
}
