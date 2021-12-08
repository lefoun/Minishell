/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:27:23 by nammari           #+#    #+#             */
/*   Updated: 2021/12/08 21:25:30 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_main_process_builtin(t_command_vars *commands)
{
	bool	is_main_process;

	is_main_process = false;
	if (ft_strcmp(commands->name[0], "cd") == 0)
		is_main_process = true;
	else if (ft_strcmp(commands->name[0], "pwd") == 0)
		is_main_process = true;
	else if (ft_strcmp(commands->name[0], "env") == 0)
		is_main_process = true;
	else if (ft_strcmp(commands->name[0], "exit") == 0)
		is_main_process = true;
	else if (ft_strcmp(commands->name[0], "export") == 0)
		is_main_process = true;
	else if (ft_strcmp(commands->name[0], "unset") == 0)
		is_main_process = true;
	else if (commands->is_assign == true)
		is_main_process = true;
	if (is_main_process == true)
		commands->is_main_process_cmd = true;
	return (is_main_process);
}
