/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_execution.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 11:03:46 by nammari           #+#    #+#             */
/*   Updated: 2021/12/11 15:26:22 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
			break ;
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
	int		i;

	init_vars_to_minus_one(&i, pipe_fds, &commands->prev_output);
	while (++i < commands->nb)
	{
		g_variables->is_child_to_kill = false;
		init_commands_struct(commands);
		commands->name = get_copy_of_com(*head, commands);
		if (i + 1 < commands->nb)
			create_pipe(pipe_fds, commands);
		init_fd_to_commands(*head, commands);
		if (commands->nb == 1 && is_main_process_builtin(commands))
			exec_builtin(commands);
		else
			fork_and_execute(commands, pipe_fds, i, head);
		advance_linked_list_ptr(head);
		close_unused_fds(pipe_fds, &commands->prev_output, i, commands);
		ft_free_tab(commands->name, 0);
	}
	g_variables->last_exit_status = wait_for_children(commands);
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
