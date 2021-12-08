/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_init_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 16:52:37 by noufel            #+#    #+#             */
/*   Updated: 2021/12/08 21:32:09 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"

void	advance_linked_list_ptr(t_token **head)
{
	t_token	*tmp;

	tmp = *head;
	while (*head != NULL && (*head)->type != PIPE)
	{
		*head = (*head)->next;
		free(tmp->value);
		ft_free_tab(tmp->cmd, 0);
		free(tmp);
		tmp = *head;
	}
	if (*head != NULL && (*head)->type == PIPE)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp->value);
		free(tmp);
	}
}

void	init_commands_struct(t_command_vars *commands)
{
	commands->input_fd = 0;
	commands->output_fd = 1;
	commands->in_head = NULL;
	commands->out_head = NULL;
	commands->is_here_doc = false;
	commands->is_assign = false;
}

void	init_vars_to_minus_one(int *i, int pipe_fds[2], int *prev_output)
{
	*i = -1;
	pipe_fds[0] = -1;
	pipe_fds[1] = -1;
	*prev_output = -1;
}
