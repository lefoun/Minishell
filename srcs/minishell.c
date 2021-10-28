/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/28 22:18:14 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



/*
** Faut il que le shell herite des variable d 'env d un precedent shell ?
** Comment set les variables d'env ?
*/


int	main(void)
{
	 char	**args;

	variables = init_env();
	args = create_args();
	printf("pepesh €\n");
	
	ft_export(args);
	printenv(variables->env);

	char **args2 = malloc(sizeof(char *) * 3);
	args2[0] = ft_strdup("PWD=");
	args2[1] = ft_strdup("OLDPWD=/Users");
	args2[3] = NULL;
	ft_export(args2);
	printenv(variables->env);

	/*
	** cd builtin TEST.

	ft_pwd();
	char **args2 = malloc(sizeof(char *) * (1 + 1));
	(void)args2;
	args2[0] = ft_strdup("/");
	args2[1] = NULL;
	ft_export(&variables->env, ft_strdup("HOME"), ft_strdup(""));
	ft_export(&variables->env, ft_strdup("PWD"), ft_strdup(""));
	ft_export(&variables->env, ft_strdup("OLDPWD"), ft_strdup(""));
	printenv(variables->env);
	ft_cd(NULL);
	ft_pwd();
	printenv(variables->env);

	**
	*/

	// ft_export(&env, ft_strdup("name"), ft_strdup("value"));
	// printenv(env);

	// ft_export(&env, ft_strdup("name3"), NULL);
	// printenv(env);

	// ft_export(&env, ft_strdup("name3"), ft_strdup("wtf"));
	// printenv(env);

	// ft_export(&env, ft_strdup("name3"), NULL);
	// printenv(env);

	// ft_export(&env, ft_strdup("name3"), ft_strdup("helloworld"));
	// ft_export(&env, ft_strdup("stone"), ft_strdup("stony"));
	// printenv(env);
	// ft_pwd();
	// ft_cd("/home/stone/42/minishell/builtins");
	// ft_pwd();
	//perror("wtf");
	// ft_pwd();
	// ft_cd("/home/stone/42/minishell/builtins");
	// ft_pwd();
	// ft_echo("hello world!", true);


	ft_exit(0);
}
