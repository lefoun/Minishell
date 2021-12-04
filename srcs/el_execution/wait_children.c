/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_children.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 14:03:29 by nammari           #+#    #+#             */
/*   Updated: 2021/12/04 19:03:15 by nammari          ###   ########.fr       */
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
		// dprintf(2, "here is stat %d\n", status);
		if (WIFEXITED(status))
		{
			// dprintf(2, "here is stat %d\n", status);
			last_exit_status = WEXITSTATUS(status);
			// dprintf(2, "heres last comd stats %d\n", last_exit_status);
		}
		else if (WIFSIGNALED(status))
		{
			// dprintf(2, "signal\n");
			last_exit_status = WTERMSIG(status) + 128;
		}
		++i;
	}
	return (last_exit_status);
}
