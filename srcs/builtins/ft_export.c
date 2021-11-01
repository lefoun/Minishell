/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:49 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/28 22:34:50 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_export(char **args)
{
	t_variable	*new;

	if (args == NULL)
		ft_env(variables->env);
	else
	{
		new = get_variables_assignations(args);
		if (new == NULL)
		{
			perror("export");
			return (errno);
		}
		add_variable(&variables->env, new);
	}
	return (0);
}
