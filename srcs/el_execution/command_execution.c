/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_execution.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 22:17:28 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/08 22:20:45 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exit_process(t_command_vars *commands, int pipe_fds[2], t_token *head)
{
	put_error(commands->name[0]);
	close(pipe_fds[0]);
	close_pipes(0, 1);
	mem_free(commands->paths, 0, commands);
	free_token_lst(head);
	exit(127);
}

int	exec_command(char **my_paths, char **argv, t_command_vars *commands)
{
	char	*path;
	char	**args;

	args = ft_split(*(argv), ' ');
	if (!args)
		return (-1);
	execve(args[0], argv, commands->env);
	path = ft_strjoin("./", *args);
	if (!path)
		return (-1);
	while (execve(path, argv, commands->env) == -1)
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

int	link_pipe_to_fd(int in, int out)
{
	if (in > -1)
	{
		dup2(in, STDIN_FILENO);
		if (in < 0)
			perror("Input Fd Dup failed");
	}
	if (out > -1)
	{
		dup2(out, STDOUT_FILENO);
		if (out < 0)
			perror("Input Fd Dup failed\n");
	}
	return (0);
}

int	fork_and_execute(t_command_vars *com, int pipe_fds[2],
	int index, int prev_output, t_token **head)
{
	int	pid;

	if (com->nb == 1 && is_main_process_builtin(com))
		return (exec_builtin(com));
	pid = fork();
	if (pid == -1)
		return (_error_('k'));
	if (pid == 0)
	{
		signal(SIGQUIT, SIG_DFL);
		if (pipe_fds[0] != -1 && index == 0)
			close(pipe_fds[0]);
		if (index == 0)
			link_pipe_to_fd(com->input_fd, com->output_fd);
		else if (index + 1 == com->nb)
			link_pipe_to_fd(prev_output, com->output_fd);
		else
			link_pipe_to_fd(prev_output, pipe_fds[1]);
		if (exec_builtin(com) != -1)
			exit_builtin_exec(pipe_fds, prev_output, com, head);
		exec_command(com->paths, com->name, com);
		exit_process(com, pipe_fds, *head);
	}
	return (0);
}
