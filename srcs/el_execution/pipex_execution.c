/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:03:46 by nammari           #+#    #+#             */
/*   Updated: 2021/12/08 20:58:21 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

int	exit_process(t_command_vars *commands, int pipe_fds[2], t_token *head)
{
	put_error(commands->name[0]);
	close(pipe_fds[0]);
	close_pipes(0, 1);
	mem_free(commands->paths, 0, commands);
	free_token_lst(head);
	exit(127);	
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

int	fork_and_execute(t_command_vars *com, int pipe_fds[2], int index, int prev_output, t_token **head)
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

char	**get_copy_of_com(t_token *head, t_command_vars *com)
{
	char	**copy;
	int		i;

	i = 0;
	while (head != NULL && head->type != CMD_NAME)
	{
		if (head->type == ASSIGN)
		{
			com->is_assign = true;
			break;
		}
		head = head->next;
	}
	while (head != NULL && head->cmd[i] != NULL)
		++i;
	copy = (char **)malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	copy[i] = NULL;
	i = -1;
	while (head && head->cmd[++i])
		copy[i] = ft_strdup(head->cmd[i]);
	return (copy);
}

int	create_pipe(int pipe_fds[2], t_command_vars *com)
{
	if (pipe(pipe_fds) == -1)
		return (_error_('p'));
	if (com->output_fd == 1)
		com->output_fd = pipe_fds[1];
	return (0);
}

int	pipex(t_command_vars *commands, t_token **head)
{
	int		pipe_fds[2];
	int		prev_output;
	int		i;

	init_vars_to_minus_one(&i, pipe_fds, &prev_output);
	while (++i < commands->nb)
	{
		init_commands_struct(commands);
		commands->name = get_copy_of_com(*head, commands);
		if (i + 1 < commands->nb)
			create_pipe(pipe_fds, commands);
		init_fd_to_commands(*head, commands);
		fork_and_execute(commands, pipe_fds, i, prev_output, head);
		advance_linked_list_ptr(head);
		close_unused_fds(pipe_fds, &prev_output, i, commands);
		ft_free_tab(commands->name, 0);
	}
	variables->last_exit_status = wait_for_children(commands);
	return (0);
}

int	pipex_exec_test(int nb_args, t_token **head, char **environ)
{
	t_command_vars	commands;

	commands.paths = get_paths(environ);
    commands.input_fd = 0;
    commands.output_fd = 1;
	commands.env = environ;
	commands.nb = nb_args;
	commands.in_head = NULL;
	commands.out_head = NULL;
	commands.is_here_doc = false;
	commands.is_main_process_cmd = false;
	if (commands.nb == 0 && *head != NULL)
	{
		init_fd_to_commands(*head, &commands);
		close_fd_chain(commands.in_head, &commands);
		close_fd_chain(commands.out_head, &commands);
	}
	else
		pipex(&commands, head);
	ft_free_tab(commands.paths, 0);
	free_token_lst(*head);
	return (0);
}
