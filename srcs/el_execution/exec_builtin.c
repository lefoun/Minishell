/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 11:40:47 by nammari           #+#    #+#             */
/*   Updated: 2021/12/08 21:53:22 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_builtin_exec(int pipe[2], int prev_output,
	t_command_vars *com, t_token **head)
{
	if (pipe[0] != -1)
		close(pipe[0]);
	if (pipe[1] != -1)
		close(pipe[1]);
	if (prev_output != -1)
		close(prev_output);
	ft_free_tab(com->name, 0);
	ft_free_tab(com->paths, 0);
	free_token_lst(*head);
	close_fd_chain(com->in_head, com);
	close_fd_chain(com->out_head, com);
	exit(0);
}

int	assign_variables(char **keyvalue)
{
	int	i;

	if (keyvalue == NULL || *keyvalue == NULL)
		return (1);
	i = 0;
	while (keyvalue[i])
	{
		assign_var(keyvalue[i]);
		++i;
	}
	return (0);
}

int	exec_builtin(t_command_vars *commands)
{
	int	exit_status;

	exit_status = -1;
	if (ft_strcmp(commands->name[0], "cd") == 0)
		exit_status = ft_cd(commands->name + 1);
	else if (ft_strcmp(commands->name[0], "echo") == 0)
		exit_status = ft_echo(commands->name + 1);
	else if (ft_strcmp(commands->name[0], "pwd") == 0)
		exit_status = ft_pwd(commands->name + 1);
	else if (ft_strcmp(commands->name[0], "env") == 0)
		exit_status = ft_env(commands->name + 1);
	else if (ft_strcmp(commands->name[0], "exit") == 0)
		exit_status = ft_exit(commands->name + 1);
	else if (ft_strcmp(commands->name[0], "export") == 0)
		exit_status = ft_export(commands->name + 1);
	else if (ft_strcmp(commands->name[0], "unset") == 0)
		exit_status = ft_unset(commands->name + 1);
	else if (commands->is_assign == true)
		exit_status = assign_variables(commands->name);
	if (exit_status != -1)
		g_variables->last_exit_status = exit_status;
	return (exit_status);
}
