/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_processed_cmd_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:53:52 by nammari           #+#    #+#             */
/*   Updated: 2021/10/28 15:45:19 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

////
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
/////

char	**get_prosseced_cmd_line(char *cmd_line)
{
	int		i;
	int		words_nb;
	char	**splited_args;
	t_vars	*variable;

	variable = malloc(sizeof(*variable));
	variable->env = create_variable("hello", "var_value");
	variable->env->next = create_variable("stony", "lalalala");
	variable->global = NULL;
	i = 0;
	words_nb = count_words_nb(cmd_line);
	if (words_nb == ERROR)
		return (NULL);
	splited_args = malloc(sizeof(*splited_args) * (words_nb + 1));
	if (splited_args == NULL)
		return (NULL);
	split_cmd_line(cmd_line, splited_args, words_nb, variable);
	// while (i < words_nb)
	// {
	// 	printf("This is word n#_%0d/%0d: |%s|\n", i, words_nb, splited_args[i]);
	// 	++i;
	// }
	return (splited_args);
}