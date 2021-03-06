/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:25:08 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/11 15:36:46 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sighandler(int signo)
{
	if (signo == SIGINT)
	{
		g_variables->last_exit_status = 130;
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	else if (signo == SIGQUIT)
	{
		return ;
	}
}

int	shell_init(char **av, char **envp)
{
	g_variables = init_env(av);
	ft_export(envp);
	set_shlvl();
	set_underscore();
	set_pwd();
	if (getenv("LS_COLORS") == NULL)
		set_lscolors();
	return (0);
}
