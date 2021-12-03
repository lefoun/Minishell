/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/03 14:32:33 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Faut il que le shell herite des variable d 'env d un precedent shell ?
** Comment set les variables d'env ?
*/

t_vars	*variables = NULL;

void debugenv(void)
{
	int i = 0;

	while (variables->envp[i] != NULL)
	{
		printf( GRN "--> %s\n" RESET, variables->envp[i]);
		i++;
	}
}

int	main(int ac, char **av, char **envp)
{
	char	*cmd;
	(void)ac;
	(void)av;
	(void)envp;

	shell_init(av, envp);
	char **args = malloc(sizeof(char *) * 6);
	args[0] = ft_strdup("LOL=wtf");
	args[1] = ft_strdup("MDRRR1RR&RRR=42");
	args[2] = ft_strdup("STOOOOOONY=sto");
	args[3] = NULL;
	ft_export(args);
	ft_env(NULL);
	t_list	*tmp = variables->environ;
	while (tmp)
	{
		printf("content => %s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	while (true)
	{
		cmd = readline("pepesh € ");
		update_history();
		ft_parser(cmd);
		free(cmd);
	}	
	return (0);
}
