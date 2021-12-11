/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 15:20:37 by nammari           #+#    #+#             */
/*   Updated: 2021/12/11 15:39:40 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_func_call(void)
{
	signal(SIGQUIT, SIG_DFL);
	signal(SIGINT, SIG_DFL);
}

void	kill_child(int signo)
{
	if (signo == SIGINT && g_variables->is_child_to_kill == true)
	{
		kill(g_variables->my_pid, SIGKILL);
	}
}

void	update_var_for_signal(int pid)
{
	if (pid != 0)
		g_variables->my_pid = pid;
	else
		g_variables->my_pid = 0;
}
