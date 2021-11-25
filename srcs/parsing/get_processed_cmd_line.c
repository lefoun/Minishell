/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_processed_cmd_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noufel <noufel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:53:52 by nammari           #+#    #+#             */
/*   Updated: 2021/11/25 08:14:10 by noufel           ###   ########.fr       */
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