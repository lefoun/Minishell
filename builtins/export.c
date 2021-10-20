/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:49 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/20 19:01:57 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_environ	*create_env_var(char *name, char *value)
{
	t_environ	*new;

	new = malloc(sizeof(t_environ));
	if (new == NULL)
		return (NULL);
	new->name = name;
	new->value = value;
	new->next = NULL;
	return (new);
}

void	add_env_var_back(t_environ **head, t_environ *new)
{
	t_environ	*env;

	if (*head == NULL)
		*head = new;
	else
	{
		env = *head;
		while (env->next != NULL)
			env = env->next;
		env->next = new;
	}
}

int export_(t_environ **env_vars,char *name, char *value)
{
    add_env_var_back(env_vars, create_env_var(name, value));
    return (0);
}
