/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:55:28 by nammari           #+#    #+#             */
/*   Updated: 2021/12/03 21:15:25 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	close_pipes(int fd_1, int fd_2)
{
	close(fd_1);
	close(fd_2);
	return (0);
}

void	close_unused_pipes(int pipe_fds[2], int *prev_output, int i)
{
	close(pipe_fds[1]);
	if (i != 0)
		close(*prev_output);
	*prev_output = pipe_fds[0];
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
