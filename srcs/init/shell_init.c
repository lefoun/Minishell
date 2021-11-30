/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stone <stone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:21:03 by stone             #+#    #+#             */
/*   Updated: 2021/11/30 21:10:31 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	set_shlvl(void)
{
	t_variable	*lvl;
	char		**new_var;
	char		*lvl_value;

	lvl = get_variable(variables->env, "SHLVL");
	if (lvl == NULL)
	{
		new_var = malloc(sizeof(char *) * 2);
		if (new_var == NULL)
			return (1);
		new_var[0] = ft_strdup("SHLVL=1");
		new_var[1] = NULL;
		ft_export(new_var);
		free(new_var);		
	}
	else
	{
		lvl_value = ft_itoa(ft_atoi(lvl->value) + 1);
		free(lvl->value);
		lvl->value = lvl_value;

	}
	return (0);
}

int	shell_init(char **av, char **envp)
{
	variables->prog_name = ft_strdup(av[0] + 2);
	if (envp[0] == NULL)
		printf("envp is empty\n");
	else
		printf("envp has env variables\n");
	ft_export(envp);
	set_shlvl();
	// char *env = getenv("TERM");
	// int slot = ttyslot();
	// printf("env => %s\n", env);
	// printf("slot => %d\n", slot);
	return (0);
}