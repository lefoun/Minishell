/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/22 17:34:10 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_variable *env = NULL;

	printf("pepesh €\n");
	printenv(env);

	ft_export(&env, ft_strdup("NEW_NAME"), ft_strdup("NEW_VALUE"));
	ft_export(&env, ft_strdup("name"), ft_strdup("value"));
	printenv(env);

	ft_export(&env, ft_strdup("name3"), NULL);
	printenv(env);

	ft_export(&env, ft_strdup("name3"), ft_strdup("wtf"));
	printenv(env);

	ft_export(&env, ft_strdup("name3"), NULL);
	printenv(env);

	ft_export(&env, ft_strdup("name3"), ft_strdup("helloworld"));
	ft_export(&env, ft_strdup("stone"), ft_strdup("stony"));
	printenv(env);
	ft_pwd();
	ft_cd("/home/stone/42/minishell/builtins");
	ft_pwd();
	//perror("wtf");
	// pwd();
	// cd("/home/stone/42/minishell/builtins");
	// pwd();
	// echo("hello world!", true);
	ft_exit(0);
}
