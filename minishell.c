/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/21 14:25:50 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_environ *env = NULL;

	printf("pepesh €\n");
	printenv(env);

	export_(&env, ft_strdup("NEW_NAME"), ft_strdup("NEW_VALUE"));
	export_(&env, ft_strdup("name"), ft_strdup("value"));
	printenv(env);

	export_(&env, ft_strdup("name3"), NULL);
	printenv(env);

	export_(&env, ft_strdup("name3"), ft_strdup("wtf"));
	printenv(env);

	export_(&env, ft_strdup("name3"), NULL);
	printenv(env);

	export_(&env, ft_strdup("name3"), ft_strdup("helloworld"));
	export_(&env, ft_strdup("stone"), ft_strdup("stony"));
	printenv(env);
	// pwd();
	// cd("/home/stone/42/minishell/builtins");
	// pwd();
	// echo("hello world!", true);
	exit_(0);
}
