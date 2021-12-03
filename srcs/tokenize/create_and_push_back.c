/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_and_push_back.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:26:43 by nammari           #+#    #+#             */
/*   Updated: 2021/12/03 21:31:00 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_elem_pushback(t_token **head, t_token *elem)
{
	t_token	*tmp;

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

t_token	*ft_create_elem(char *content, int type)
{
	t_token	*new;

	if (content == NULL)
		return (NULL);
	new = malloc(sizeof(*new));
	if (new == NULL)
	{
		free(content);
		return (NULL);
	}
	new->value = content;
	new->cmd = NULL;
	new->type = type;
	new->next = NULL;
	return (new);
}
