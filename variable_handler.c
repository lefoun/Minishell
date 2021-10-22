/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:14:01 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/22 17:18:32 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


t_variable	*create_variable(char *name, char *value)
{
	t_variable	*new;

	new = malloc(sizeof(t_variable));
	if (new == NULL)
		return (NULL);
	new->name = name;
	if (value == NULL)
		new->value = NULL;
	else
		new->value = value;
	new->next = NULL;
	return (new);
}

static void	change_variable_value(t_variable *env, t_variable *new)
{
	if (env->value != NULL)
		free(env->value);
	env->value = new->value;
	free(new->name);
	free(new);
}

void	add_variable(t_variable **head, t_variable *new)
{
	t_variable	*env;

	if (*head == NULL)
		*head = new;
	else
	{
		env = *head;
		while (env != NULL)
		{
			if (strcmp(env->name, new->name) == 0)
			{
				change_variable_value(env, new);
				break ;
			}
			if (env->next == NULL)
			{
				env->next = new;
				break ;
			}
			env = env->next;
		}
	}
}
