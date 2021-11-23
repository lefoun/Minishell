/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:55:28 by nammari           #+#    #+#             */
/*   Updated: 2021/11/23 15:20:43 by nammari          ###   ########.fr       */
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
    // dprintf(2, "Here's pipefd[0] %d and [1] %d\n", pipe_fds[0], pipe_fds[1]);
	close(pipe_fds[1]);
	if (i != 0)
		close(*prev_output);
    *prev_output = pipe_fds[0];
	
}