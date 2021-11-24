/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noufel <noufel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:55:28 by nammari           #+#    #+#             */
/*   Updated: 2021/11/24 17:37:54 by noufel           ###   ########.fr       */
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

void    close_unused_fd_chain(t_fd_chain *head)
{
	t_fd_chain *tmp;

	tmp = head;
    while (head != NULL)
    {
        if (head->next == NULL)
			return ;
		else
		{
            close(head->fd);
		}
		dprintf(2, "This is head-> fd %d\n", head->fd);
		head = head->next;
		free(tmp);
		tmp = head;
    }
}