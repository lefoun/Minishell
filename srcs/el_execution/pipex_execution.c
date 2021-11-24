/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noufel <noufel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:03:46 by nammari           #+#    #+#             */
/*   Updated: 2021/11/24 18:02:04 by noufel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	exec_command(char **my_paths, char **argv, t_command_vars *commands)
{
	char	*path;
	char	**args;

	// int i = -1;
	// while (argv[++i])
	// 	dprintf(2, "This is argv[%d]: |%s|\n", i, argv[i]);
	args = ft_split(*(argv), ' ');
	if (!args)
		return (-1);
	execve(args[0], argv, commands->env);
	path = ft_strjoin("./", *args);
	if (!path)
		return (-1);
	while (execve(path, argv, commands->env) == -1)
	{
		// dprintf(2, "This is path %s\n", path);
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

// int	apply_redirection(int in, int out, t_token **head)
// {
// 	int	fd;

// 	if (*head == NULL || (*head)->next == NULL)
// 		return (1);
// 	if ((*head)->next->type == REDIR_IN)
// 	{
// 		// dprintf(2, "here\n");
// 		fd = open((*head)->next->value, O_RDONLY);
// 		dup2(in, fd);
// 		close(in);
// 	}
// 	else if ((*head)->next->type == REDIR_OUT_APPEND || (*head)->next->type == REDIR_OUT_TRUNC)
// 	{
// 		// dprintf(2, "here2\n");
// 		fd = open((*head)->next->value, O_RDWR);
// 		dup2(fd, out);
// 		//close(out);
// 		// dprintf(2, "This is out %d and fd %d\n", out, fd);
// 	}
// 	// dprintf(2, "here3\n");
// 	return (0);
// }

int	exit_process(t_command_vars *commands, int pipe_fds[2])
{
	put_error(commands->name[0]);
	close(pipe_fds[0]);
	close_pipes(0, 1);
	mem_free(commands->paths, 0, commands);
	exit(EXIT_FAILURE);	
}

int	link_pipe_to_fd(int in, int out, t_token **head)
{
	(void)head;
	dup2(in, STDIN_FILENO);
	if (in < 0)
		perror("In failed");
	out = dup2(out, STDOUT_FILENO);
	if (out < 0)
		perror("out failed\n");
	// apply_redirection(in, out, head);
	return (0);
}

char	**get_command(t_token **head)
{
	t_token	*tmp;

	tmp = *head;
	while (tmp != NULL && (tmp)->type != CMD_NAME)
		tmp = tmp->next;
	if (tmp == NULL)
		return (NULL);
	return (tmp->cmd);
}

int	fork_and_execute(t_command_vars *com, int pipe_fds[2], int index, int prev_output, t_token **head)
{
	int	pid;
	
	pid = fork();
	if (pid == -1)
		return (_error_('k'));
	if (pid == 0)
	{
		if (index == 0)
		{
			close(pipe_fds[0]);
			link_pipe_to_fd(com->input_fd, com->output_fd, head);
		}
		else if (index + 1 == com->nb)
			link_pipe_to_fd(prev_output, com->output_fd, head);
		else
			link_pipe_to_fd(prev_output, pipe_fds[1], head);
		if (exec_command(com->paths, com->name, com) == -1)
			exit_process(com, pipe_fds);
	}
	return (1);
}

void	advance_linked_list_ptr(t_token **head)
{
	*head = (*head)->next;
	if (*head != NULL && (*head)->type == PIPE)
		*head = (*head)->next;
}

int	pipex(t_command_vars *commands, t_token **head)
{
	int		pipe_fds[2];
	int		prev_output;
	int		i;

	i = -1;
	pipe_fds[0] = -1;
	pipe_fds[1] = -1;
	prev_output = -1;
	while (++i < commands->nb)
	{
		init_fd_to_commands(*head, commands);
		if (i + 1 < commands->nb)
		{
			if (pipe(pipe_fds) == -1)
				return (_error_('p'));
			commands->output_fd = pipe_fds[1];
		}
		commands->name = get_command(head);
		fork_and_execute(commands, pipe_fds, i, prev_output, head);
		close_unused_pipes(pipe_fds, &prev_output, i);
		if (i + 1 == commands->nb)
			close(pipe_fds[0]);
		advance_linked_list_ptr(head);
	}
	wait_for_children(commands->nb);
	return (0);
}

int	pipex_exec_test(int nb_args, t_token **head, char **environ)
{
	t_command_vars	commands;

	commands.paths = get_paths(environ);
	commands.here_doc = false;
	// commands.name = "hello";
    commands.input_fd = 0;
    commands.output_fd = 1;
	commands.env = environ;
	commands.nb = nb_args;
	commands.in_head = NULL;
	commands.out_head = NULL;
	pipex(&commands, head);
	return (0);
}