/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/03 18:39:51 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_vars	*variables = NULL;

int	main(int ac, char **av, char **envp)
{
	char	*cmd;
	(void)ac;
	(void)av;
	(void)envp;

	shell_init(av, envp);
	char **args = malloc(sizeof(char *) * 5);
	args[0] = ft_strdup("YO=MDR");
	args[1] = NULL;
	// ft_export(args);
	ft_env(args);
	while (true)
	{
		cmd = readline("pepesh € ");
		update_history();
		ft_parser(cmd);
		free(cmd);
	}	
	return (0);
}
