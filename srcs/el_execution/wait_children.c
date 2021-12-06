/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:03:29 by nammari           #+#    #+#             */
/*   Updated: 2021/12/06 12:51:44 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"

int	wait_for_children(t_command_vars *com)
{
	int	i;
	int	status;
	int last_exit_status;

	i = 0;
	status = 0;
	last_exit_status = variables->last_exit_status;
	if (com->is_main_process_cmd == true)
		return (last_exit_status);
	while (i < com->nb)
	{
		wait(&status);
		if (WIFEXITED(status))
			last_exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			last_exit_status = WTERMSIG(status) + 128;
		++i;
	}
	return (last_exit_status);
}
