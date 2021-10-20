/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/21 00:23:31 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	t_environ *env_vars = NULL;

	printf("pepesh €\n");
	env(env_vars);
	export_(&env_vars, ft_strdup("NEW_NAME"), ft_strdup("NEW_VALUE"));
	export_(&env_vars, ft_strdup("name"), ft_strdup("value"));
	env(env_vars);
	// pwd();
	// cd("/home/stone/42/minishell/builtins");
	// pwd();
	// echo("hello world!", true);
	exit_(0);
}
