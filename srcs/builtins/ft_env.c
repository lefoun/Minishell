/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:43 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/03 17:50:23 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(char **args)
{
	t_variable	*env;

	(void)args;
	env = variables->env;
	while (env != NULL)
	{
		printf("%s=%s\n", env->name, env->value);
		env = env->next;
	}
	return (0);
}
