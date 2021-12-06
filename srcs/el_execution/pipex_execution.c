/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:03:46 by nammari           #+#    #+#             */
/*   Updated: 2021/12/06 13:05:14 by nammari          ###   ########.fr       */
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
	dup2(in, STDIN_FILENO);
	if (in < 0)
		perror("Input Fd Dup failed");
	dup2(out, STDOUT_FILENO);
	if (out < 0)
		perror("Input Fd Dup failed\n");
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
		if (index == 0)
		{
			close(pipe_fds[0]);
			link_pipe_to_fd(com->input_fd, com->output_fd);
		}
		else if (index + 1 == com->nb)
			link_pipe_to_fd(prev_output, com->output_fd);
		else
			link_pipe_to_fd(prev_output, pipe_fds[1]);
		if (exec_builtin(com) != -1)
			exit(0);
		exec_command(com->paths, com->name, com);
		exit_process(com, pipe_fds, *head);
	}
	return (0);
}

char	**get_assign_value(t_token *head)
{
	t_token	*tmp;
	char	**str;
	int		i;

	if (head == NULL)
		return (NULL);
	i = 0;
	tmp = head;
	while (head && head->type == ASSIGN)
	{
		head = head->next;
		++i;
	}
	str = malloc(sizeof(char *) * (i + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (tmp && tmp->type == ASSIGN)
	{
		str[i++] = ft_strdup(tmp->value);
		tmp = tmp->next;
	}
	str[i] = NULL;
	return (str);
}

char	**get_copy_of_com(t_token *head, t_command_vars *com)
{
	char	**copy;
	int		i;
	int		len;

	i = 0;
	len = 0;
	com->is_assign = false;
	if (head && head->type == ASSIGN)
		com->is_assign = true;
	while (head && head->cmd[len])
		++len;
	copy = (char **)malloc(sizeof(char *) * (len + 1));
	if (!copy)
		return (NULL);
	while (head->cmd[i])
	{
		copy[i] = ft_strdup(head->cmd[i]);
		++i;
	}
	copy[i] = NULL;
	return (copy);
}

int	pipex(t_command_vars *commands, t_token **head)
{
	int		pipe_fds[2];
	int		prev_output;
	int		i;

	init_vars_to_minus_one(&i, pipe_fds, &prev_output);
	while (++i < commands->nb)
	{
		commands->name = get_copy_of_com(*head, commands);
		init_commands_struct(commands);
		init_fd_to_commands(*head, commands);
		if (i + 1 < commands->nb)
		{
			if (pipe(pipe_fds) == -1)
				return (_error_('p'));
			if (commands->output_fd == 1)
				commands->output_fd = pipe_fds[1];
		}
		advance_linked_list_ptr(head);
		fork_and_execute(commands, pipe_fds, i, prev_output, head);
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
	pipex(&commands, head);
	ft_free_tab(commands.paths, 0);
	free_token_lst(*head);
	return (0);
}
