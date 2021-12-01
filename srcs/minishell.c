/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/01 21:06:43 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Faut il que le shell herite des variable d 'env d un precedent shell ?
** Comment set les variables d'env ?
*/

t_vars	*variables = NULL;

int	main(int ac, char **av, char **envp)
{
	(void)ac;
	char	*cmd_line;

	shell_init(av, envp);
	// int i = 0;
	while (true)
	{
		cmd_line = readline("pepesh € ");
		rl_on_new_line();
		(void)cmd_line;
		// printf("cmd_line => |%s|\n", cmd_line);
		// printf("rl_line_buffer => %s\n", rl_line_buffer);

		add_history(rl_line_buffer);
		// rl_replace_line("yaaah", 1);
		// printf("rllinebuf => %s\n", rl_line_buffer);

		// if (i == 1)
		// 	rl_redisplay();
		// i++;
	}
	return (0);
}
