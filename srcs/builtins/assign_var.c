/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_var.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 17:07:46 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/08 21:51:06 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_variable_name(char *str)
{
	int		len;
	char	*name;

	len = 0;
	while (str[len] != '=' && str[len] != '\0')
		len++;
	name = malloc(sizeof(char) * len + 1);
	if (name == NULL)
		return (NULL);
	len = 0;
	while (str[len] != '=' && str[len] != '\0')
	{
		name[len] = str[len];
		len++;
	}
	name[len] = '\0';
	return (name);
}

static char	*get_variable_value(char *str)
{
	int		len;
	char	*value;

	while (*str != '=' && *str != '\0')
		str++;
	if (*str == '=')
		str++;
	len = ft_strlen(str);
	value = malloc(sizeof(char) * len + 1);
	if (value == NULL)
		return (NULL);
	if (len == 0)
		value[0] = '\0';
	else
	{
		len = 0;
		while (str[len] != '\0')
		{
			value[len] = str[len];
			len++;
		}
		value[len] = '\0';
	}
	return (value);
}

static t_variable	*create_variable(char *str)
{
	t_variable	*new;

	new = malloc(sizeof(t_variable));
	if (new == NULL)
		return (NULL);
	new->name = get_variable_name(str);
	new->value = get_variable_value(str);
	new->next = NULL;
	return (new);
}

static bool	is_in_env(char *name)
{
	t_variable	*tmp;

	tmp = g_variables->env;
	while (tmp != NULL)
	{
		if (ft_strcmp(name, tmp->name) == 0)
			return (true);
		tmp = tmp->next;
	}
	return (false);
}

void	assign_var(char *keyvalue)
{
	t_variable		*new;

	new = create_variable(keyvalue);
	if (is_in_env(new->name))
	{
		if (is_valid_identifier(new->name, ASSIGNMENT))
			add_variable(&g_variables->env, new);
		else
		{
			free(new->name);
			free(new->value);
			free(new);
		}
	}
	else
	{
		if (is_valid_identifier(new->name, ASSIGNMENT))
			add_variable(&g_variables->global, new);
		else
		{
			free(new->name);
			free(new->value);
			free(new);
		}
	}
}
