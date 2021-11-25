/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noufel <noufel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:14:01 by sdummett          #+#    #+#             */
/*   Updated: 2021/11/25 08:13:45 by noufel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	int			len;

	if (*head == NULL)
		*head = new;
	else
	{
		env = *head;
		while (env != NULL)
		{
			len = get_greatest_len(env->name, new->name);
			if (strncmp(env->name, new->name, len) == 0)
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
