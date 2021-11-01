/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:49 by sdummett          #+#    #+#             */
/*   Updated: 2021/11/01 19:49:13 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int ft_export(char **args)
{
	t_variable	*new;

	if (args == NULL)
		ft_env(NULL);
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
