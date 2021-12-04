/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:55:28 by nammari           #+#    #+#             */
/*   Updated: 2021/12/04 17:30:09 by nammari          ###   ########.fr       */
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

void	close_unused_fds(int pipe_fds[2], int *prev_output, int i, t_command_vars *com)
{
	if (i + 1 == com->nb && pipe_fds[0] != -1)
		close(pipe_fds[0]);
	if (pipe_fds[1] != -1)
		close(pipe_fds[1]);
	if (i != 0 && *prev_output != -1)
		close(*prev_output);
	*prev_output = pipe_fds[0];
	close_unused_fd_chain(com->in_head);
	close_unused_fd_chain(com->out_head);
}

void	close_unused_fd_chain(t_fd_chain *head)
{
	t_fd_chain	*tmp;

	tmp = head;
	while (head != NULL)
	{
		if (head->next == NULL)
			return ;
		else
		{
			close(head->fd);
		}
		head = head->next;
		free(tmp);
		tmp = head;
	}
}
