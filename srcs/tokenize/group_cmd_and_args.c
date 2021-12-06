/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_cmd_and_args.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 17:46:59 by nammari           #+#    #+#             */
/*   Updated: 2021/12/06 11:31:16 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_nb_args(t_token *head)
{
	int		nb_args;

	nb_args = 0;
	while (head && head->type != PIPE)
	{
		if (head->type == CMD_SUFFIX)
			++nb_args;
		head = head->next;
	}
	return (nb_args);
}

void	get_args(t_token *head)
{
	int		i;
	int		nb_args;
	t_token	*tmp;

	i = 0;
	nb_args = get_nb_args(head);
	head->cmd = malloc(sizeof(char *) * (nb_args + 2));
	if (head->cmd == NULL)
		return ;
	tmp = head;
	head->cmd[i] = ft_strdup(tmp->value);
	while(tmp && tmp->type != PIPE)
	{
		if (tmp->type == CMD_SUFFIX)
			head->cmd[++i] = ft_strdup(tmp->value);
		tmp = tmp->next;
	}
	head->cmd[++i] = NULL;
}

t_token	*group_cmd_and_args(t_token **head)
{
	t_token	*tmp;
	t_token	*previous;

	if (head == NULL || *head == NULL)
		return (NULL);
	tmp = *head;
	while (tmp && (tmp)->type != CMD_NAME)
		tmp = (tmp)->next;
	previous = tmp;
	while (tmp)
	{
		// if (tmp->type == ASSIGN)
		// 	get_assign_values(&tmp);
		if (tmp->type == CMD_NAME)
			get_args(tmp);
		else if (tmp->type == CMD_SUFFIX)
		{
			previous->next = tmp->next;
			free(tmp->value);
			free(tmp);
			tmp = previous;
		}
		previous = tmp;
		tmp = tmp->next;
	}
	return (*head);
}
