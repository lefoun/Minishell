/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:25:08 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/08 22:02:05 by sdummett         ###   ########.fr       */
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

void	init_signal_struct(struct sigaction *sa)
{
	struct sigaction	sa_quit;

	sa_quit.sa_handler = SIG_IGN;
	sa->sa_handler = &sighandler;
	sa->sa_flags = SA_RESTART;
	sigaction(SIGINT, sa, NULL);
	sigaction(SIGQUIT, &sa_quit, NULL);
}

int	shell_init(char **av, char **envp, struct sigaction *sa)
{
	g_variables = init_env(av);
	init_signal_struct(sa);
	ft_export(envp);
	set_shlvl();
	set_underscore();
	set_pwd();
	if (getenv("LS_COLORS") == NULL)
		set_lscolors();
	return (0);
}
