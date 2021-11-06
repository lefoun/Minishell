/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/11/06 20:19:55 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



/*
** Faut il que le shell herite des variable d 'env d un precedent shell ?
** Comment set les variables d'env ?
*/

t_vars	*variables = NULL;

int	main(void)
{
	char	**args;

	variables = init_env();
	printf("pepesh €\n");

	
	(void)args;
	args = malloc(sizeof(char *) * 3);
	args[0] = ft_strdup("2namee=value");
	args[1] = ft_strdup("name2=value2");
	args[2] = NULL;
	ft_export(args);
	ft_env(NULL);
	args[0] = ft_strdup("nameee");
	args[1] = NULL;
			
	ft_unset(args);
	printf("AFTER UNSET\n");
	ft_env(NULL);

	char *varname = ft_strdup("name");
	t_variable *tmp = get_variable(variables->env, varname);
	if (tmp != NULL)
	{
		printf("tmp->name  : %s\n", tmp->name);
		printf("tmp->value : %s\n", tmp->value);
	}



	/* exit TESTS
	**

	char **args2 = malloc(sizeof(char *) * 3);
	args2[0] = ft_strdup("242");
	args2[1] = NULL;
	//args2[1] = ft_strdup("test");
	args2[2] = NULL;
	ft_pwd(args2);
	ft_exit(args2);
	//ft_exit(args2);	
	**
	*/

	/* unset TESTS
	**

	char **args2 = malloc(sizeof(char *) * 3);
	args2[0] = ft_strdup("PWD=");
	args2[1] = ft_strdup("OLDPWD=/Users");
	args2[2] = NULL;
	ft_export(args2);
	ft_export(NULL);

	args = create_args();
	ft_env(NULL);
	printf("ENSUITE\n");
	int ret = ft_unset(args);
	printf("ret = %d\n", ret);
	ft_env(NULL);
	ft_unset(args);
	ft_unset(args);

	**
	*/

	/*
	** pwd and echo TESTS

	ft_pwd(NULL);
	ft_pwd(args);
	ft_echo(args);
	
	**
	*/

	/*
	** export TESTS

	ft_export(args);
	printenv(variables->env);
	char **args2 = malloc(sizeof(char *) * 3);
	args2[0] = ft_strdup("PWD=");
	args2[1] = ft_strdup("OLDPWD=/Users");
	args2[3] = NULL;
	ft_export(args2);
	printenv(variables->env);
	ft_export(NULL);

	**
	*/

	/*
	** cd builtin TESTS.

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
}
