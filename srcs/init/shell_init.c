/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:25:08 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/02 17:55:04 by sdummett         ###   ########.fr       */
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
int	shell_init(char **envp)
{
	debug_printenv(envp);
	variables = init_env(envp);
	return (0);
}