/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/20 19:05:30 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	printf("pepesh €\n");
	t_environ *env_vars = NULL;
	char name[] = "NEW_NAME";
	char value[] = "new_value";
	
	env(env_vars);
	export_(&env_vars, name, value);
	export_(&env_vars, name, value);
	env(env_vars);
	// pwd();
	// cd("/Users/sdummett/minishell/builtins");
	// pwd();
	// echo("hello world!", true);

	return (0);
}
