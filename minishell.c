/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/22 18:26:47 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_variable *env = NULL;
	char	**args;

	args = create_args();
	return (0);
	printf("pepesh €\n");
	printenv(env);

	ft_export(&env, args);

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
