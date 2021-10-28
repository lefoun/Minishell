/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/28 17:30:15 by sdummett         ###   ########.fr       */
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
	return (0);
	printf("pepesh €\n");
	printenv(variables->env);

	ft_export(&variables->env, args);

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
