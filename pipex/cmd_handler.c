/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 16:43:51 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/14 16:44:41 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/*
** Parser les arguments et les envoyer aux commandes respectives
*/

int	continue_cmd2(int fd, char **args, char **path)
{
	int	fdstdout;

	fdstdout = dup2(fd, STDOUT_FILENO);
	close(fd);
	if (fdstdout < 0)
	{
		perror("dup2");
		free_args_path(args, path);
		return (3);
	}
	exec_cmd(args, path);
	free_args_path(args, path);
	return (4);
}

int	cmd2(int pipefd[], char *file, char **args, char **path)
{
	int	fd;

	close(pipefd[1]);
	fd = dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	if (fd < 0)
	{
		perror("dup2");
		free_args_path(args, path);
		return (1);
	}
	fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
	{
		perror("open");
		free_args_path(args, path);
		return (2);
	}
	return (continue_cmd2(fd, args, path));
}

int	continue_cmd1(int fd, char **args, char **path)
{
	int	fdstdin;

	fdstdin = dup2(fd, STDIN_FILENO);
	close(fd);
	if (fdstdin < 0)
	{
		perror("dup2");
		free_args_path(args, path);
		return (3);
	}
	exec_cmd(args, path);
	free_args_path(args, path);
	return (4);
}

int	cmd1(int pipefd[], char *file, char **args, char **path)
{
	int	fd;

	close(pipefd[0]);
	fd = dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[1]);
	if (fd < 0)
	{
		perror("dup2");
		free_args_path(args, path);
		return (1);
	}
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		free_args_path(args, path);
		return (2);
	}
	return (continue_cmd1(fd, args, path));
}
