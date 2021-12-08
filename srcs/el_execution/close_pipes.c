/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:55:28 by nammari           #+#    #+#             */
/*   Updated: 2021/12/08 21:32:49 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include "execution.h"

int	close_pipes(int fd_1, int fd_2)
{
	close(fd_1);
	close(fd_2);
	return (0);
}

void	close_fd_chain(t_fd_chain *head, t_command_vars *com)
{
	t_fd_chain	*tmp;

	tmp = head;
	while (head != NULL)
	{
		tmp = head->next;
		if (com->is_here_doc)
			unlink("here_doc");
		close(head->fd);
		free(head->file_name);
		free(head);
		head = tmp;
	}
}

void	close_unused_fds(int pipe_fds[2], int *prev_output,
	int i, t_command_vars *com)
{
	if (i + 1 == com->nb && pipe_fds[0] != -1)
		close(pipe_fds[0]);
	if (pipe_fds[1] != -1)
		close(pipe_fds[1]);
	if (i != 0 && *prev_output != -1)
		close(*prev_output);
	*prev_output = pipe_fds[0];
	close_fd_chain(com->in_head, com);
	com->in_head = NULL;
	close_fd_chain(com->out_head, com);
	com->out_head = NULL;
}

void	close_unused_fd_chain(t_fd_chain **head)
{
	t_fd_chain	*tmp;

	tmp = *head;
	while (*head != NULL && (*head)->next != NULL)
	{
		*head = (*head)->next;
		close(tmp->fd);
		free(tmp->file_name);
		free(tmp);
		tmp = *head;
	}
}
