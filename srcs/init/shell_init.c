/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 17:25:08 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/03 21:20:55 by sdummett         ###   ########.fr       */
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
		free(new_var[0]);
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

static int	set_underscore(void)
{
	char	**new_var;

	new_var = malloc(sizeof(char **) * 2);
	if (new_var == NULL)
		return (1);
	new_var[0] = ft_strdup("_=histappend");
	new_var[1] = NULL;
	ft_export(new_var);
	free(new_var[0]);
	free(new_var);
	return (0);
}

static int	set_lscolors(void)
{
	char	**new_var;

	new_var = malloc(sizeof(char **) * 2);
	if (new_var == NULL)
		return (1);
	new_var[0] = ft_strdup("LS_COLORS=");
	new_var[1] = NULL;
	ft_export(new_var);
	free(new_var[0]);
	free(new_var);
	return (0);
}

static int	set_pwd(void)
{
	t_variable	*pwd;
	char		**new_var;
	char		*cwd;

	cwd = call_getcwd();
	new_var = malloc(sizeof(char **) * 2);
	if (new_var == NULL)
		return (1);
	new_var[0] = ft_strdup("PWD=");
	new_var[1] = NULL;
	ft_export(new_var);
	pwd = get_variable(variables->env, "PWD");
	free(pwd->value);
	pwd->value = cwd;
	free(new_var[0]);
	free(new_var);
	return (0);
}

int	shell_init(char **av, char **envp)
{
	variables = init_env(av);
	ft_export(envp);
	set_shlvl();
	set_underscore();
	set_pwd();
	if (getenv("LS_COLORS") == NULL)
		set_lscolors();
	return (0);
}
