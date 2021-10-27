/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variables_assignations.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 17:05:20 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/22 18:10:04 by sdummett         ###   ########.fr       */
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
	{
		perror("");
		return (NULL);
	}
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
	len = 0;
	while (str[len] != '\0')
		len++;
	value = malloc(sizeof(char) * len + 1);
	if (value == NULL || len == 0)
	{
		perror("");
		free(value);
		return (NULL);
	}
	len = 0;
	while (str[len] != '\0')
	{
		value[len] = str[len];
		len++;
	}
	value[len] = '\0';
	return (value);
}

t_variable	*get_variables_assignations(char **args)
{
	int			i;
	char		*name;
	char		*value;
	t_variable	*parsed_variables;

	parsed_variables = NULL;
	i = 0;
	while (args[i] != NULL)
	{
		name = get_variable_name(args[i]);
		if (name == NULL)
		{
			perror("");
			//free(parsed_variables);
			return (NULL);
		}
		value = get_variable_value(args[i]);
		add_variable(&parsed_variables, create_variable(name, value));
		i++;
	}
	return (parsed_variables);
}