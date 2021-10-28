/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 03:04:15 by stone             #+#    #+#             */
/*   Updated: 2021/08/14 17:33:57 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	init_path_type(t_path *path_type)
{
	path_type->is_absolute = false;
	path_type->is_relative = false;
	path_type->is_dot_slash = false;
}

void	check_path(char *path, t_path *path_type)
{
	int	i;

	init_path_type(path_type);
	if (path[0] == '/')
	{
		path_type->is_absolute = true;
		return ;
	}
	if (path[0] == '.' && path[1] == '/')
	{
		path_type->is_relative = true;
		path_type->is_dot_slash = true;
		return ;
	}
	i = 0;
	while (path[i] != '\0')
	{
		if (path[i] == '/')
		{
			path_type->is_relative = true;
			return ;
		}
		i++;
	}
}

void	exec_cmd(char **args, char **path)
{
	t_path	path_type;
	int		i;

	check_path(args[0], &path_type);
	if (path_type.is_relative || path_type.is_absolute)
	{
		if (path_type.is_dot_slash)
			execve(args[0] + 2, args, NULL);
		else
			execve(args[0], args, NULL);
	}
	else
	{
		i = 0;
		while (path[i] != NULL)
		{
			execve(path[i], args, NULL);
			i++;
		}
	}
	perror(args[0]);
	free_args_path(args, path);
}

int	cmd(int pipein, int pipeout, char **args, char **path)
{
	int	fdin;
	int	fdout;

	fdin = dup2(pipein, STDIN_FILENO);
	close(pipein);
	if (fdin < 0)
	{
		perror("dup2");
		return (1);
	}
	fdout = dup2(pipeout, STDOUT_FILENO);
	close(pipeout);
	if (fdout < 0)
	{
		perror("dup2");
		return (2);
	}
	exec_cmd(args, path);
	close(fdout);
	return (2);
}
