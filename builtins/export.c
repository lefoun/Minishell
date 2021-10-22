/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:49 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/22 15:44:29 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_environ	*create_variable(char *name, char *value)
{
	t_environ	*new;

	new = malloc(sizeof(t_environ));
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

void	change_variable_value(t_environ *env, t_environ *new)
{
	printf("Entered change_variable\n");
	if (env->value != NULL)
		free(env->value);
	env->value = new->value;
	free(new->name);
	free(new);
}

void	add_variable(t_environ **head, t_environ *new)
{
	t_environ	*env;

	if (*head == NULL)
		*head = new;
	else
	{
		env = *head;
		while (env != NULL)
		{
			printf("env->name: %s | new->name: %s\n", env->name, new->name);
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

int export_(t_environ **env, char *name, char *value)
{
	t_environ	*new;

	new = create_variable(name, value);
	if (new == NULL)
	{
		perror("");
		return (errno);
	}
	add_variable(env, new);
    return (0);
}
