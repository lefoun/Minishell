/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 18:02:05 by nammari           #+#    #+#             */
/*   Updated: 2021/08/02 19:51:43 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	exec_command(char **my_paths, char **argv, t_command_vars *commands)
{
	char	*path;
	char	**args;

	args = ft_split(*(argv), ' ');
	if (!args)
		return (-1);
	execve(args[0], args, commands->env);
	path = ft_strjoin("./", *args);
	if (!path)
		return (-1);
	while (execve(path, args, commands->env) == -1)
	{
		free(path);
		if (!my_paths)
			return (mem_free(args, 0, commands));
		path = ft_strjoin(*my_paths, *args);
		if (!path)
			return (mem_free(args, 0, commands));
		++my_paths;
	}
	free(path);
	return (mem_free(args, 0, commands));
}

int	ft_fork(t_command_vars *commands, int in, int out, int pipe_fds[2])
{
	int	pid;

	pid = fork();
	if (pid == -1)
		return (_error_('k'));
	if (pid == 0)
	{
		if (commands->is_first_command == true)
			close(pipe_fds[0]);
		dup2(in, STDIN_FILENO);
		if (close(in) == -1)
			exit(EXIT_FAILURE);
		dup2(out, STDOUT_FILENO);
		if (out != -1)
			close(out);
		if (exec_command(commands->paths, commands->name, commands) == -1)
		{
			put_error(commands->name[0]);
			close(pipe_fds[0]);
			close_pipes(0, 1);
			mem_free(commands->paths, 0, commands);
			exit(EXIT_FAILURE);
		}
	}
	return (0);
}

int	call_fork(t_command_vars *com, int pipe_fds[2], int index, int prev_output)
{
	int	ret;

	com->is_first_command = false;
	if (index == 0)
	{
		com->is_first_command = true;
		ret = ft_fork(com, com->input_fd, pipe_fds[1], pipe_fds);
	}
	else if (index + 1 == com->nb)
	{
		ret = ft_fork(com, prev_output, com->output_fd, pipe_fds);
	}
	else
	{
		ret = ft_fork(com, prev_output, pipe_fds[1], pipe_fds);
	}
	if (ret == 1)
	{
		close_pipes(pipe_fds[1], pipe_fds[0]);
		return (-1);
	}
	return (1);
}

int	pipex(t_command_vars *commands)
{
	int		pipe_fds[2];
	int		prev_output;
	int		ret;
	int		i;

	i = -1;
	while (++i < commands->nb)
	{
		if (i + 1 < commands->nb)
			if (pipe(pipe_fds) == -1)
				return (_error_('p'));
		++commands->name;
		ret = call_fork(commands, pipe_fds, i, prev_output);
		close(pipe_fds[1]);
		if (i != 0)
			close(prev_output);
		if (ret != -1)
			prev_output = pipe_fds[0];
	}
	i = -1;
	while (++i < commands->nb)
		wait(NULL);
	return (0);
}

int	main(int argc, char **argv, char *env[])
{
	t_command_vars	commands;

	if (argc < 5)
		return (_error_('a'));
	commands.paths = get_paths(env);
	commands.here_doc = false;
	commands.name = argv + 1;
	if (init_command_fds(&commands, argv, argc) == -1)
	{
		mem_free(commands.paths, 0, &commands);
		unlink("here_doc");
		return (-1);
	}
	commands.env = env;
	commands.nb = argc - 3;
	if (commands.here_doc == true)
		commands.nb = argc - 4;
	pipex(&commands);
	mem_free(commands.paths, 0, &commands);
	if (commands.here_doc == true)
		unlink("here_doc");
	exit(0);
}
