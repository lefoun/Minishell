/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stone <stone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:27 by sdummett          #+#    #+#             */
/*   Updated: 2021/11/22 18:30:15 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** chdir seems to handle ".." without to expand it 
** (test with all environment variable unset)
*/

static int	exec_cd_with_home_var(void)
{
	t_variable	*var;

	var = get_variable(variables->env, "HOME");
	if (var == NULL)
	{
		write(2, "pepesh: cd: HOME not set\n", 25);
		return (1);
	}
	chdir(var->value);
	return (0);
}

static void	edit_env(char *olddirectory)
{
	char		*cwd;
	t_variable	*env_oldpwd;
	t_variable	*env_pwd;

	cwd = call_getcwd();
	env_oldpwd = get_variable(variables->env, "OLDPWD");
	env_pwd = get_variable(variables->env, "PWD");
	if (env_oldpwd != NULL)
		env_oldpwd->value = olddirectory;
	else
		free(olddirectory);
	if (env_pwd != NULL)
		env_pwd->value = cwd;
	else
		free(cwd);
}

int	ft_cd(char **args)
{
	char	*str;
	char	*oldpwd;

	oldpwd = call_getcwd();
	if (args == NULL)
	{
		if (exec_cd_with_home_var() == 1)
			return (1);
		edit_env(oldpwd);
	}
	else
	{
		if (chdir(args[0]) < 0)
		{
			str = strerror(errno);
			printf("cd: %s: %s\n", str, args[0]);
			return (1);
		}
		edit_env(oldpwd);
	}
	return (0);
}
