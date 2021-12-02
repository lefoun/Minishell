/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:25:08 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/02 17:59:06 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	debug_printenv(char **envp)
{
	int	i = 0;
	while (envp[i] != NULL)
	{
		printf("## %s\n", envp[i]);
		i++;
	}
}
int	shell_init(char **av, char **envp)
{
	debug_printenv(envp);
	variables = init_env(av, envp);
	return (0);
}