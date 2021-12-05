/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:49 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/05 15:21:02 by sdummett         ###   ########.fr       */
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

static void	check_assignment_variables(char *name)
{
	t_variable	*tmp;
	char		**args;

	args = malloc(sizeof(char *) * 2);
	tmp = variables->global;
	while (tmp != NULL)
	{
		if (ft_strcmp(name, tmp->name) == 0)
		{
			args[0] = name;
			args[1] = NULL;
			ft_unset(args);
			free(args);
			return ;
		}
		tmp = tmp->next;
	}
	free(args);
}

int	ft_export(char **args)
{
	t_variable		*new;
	bool			all_set;
	unsigned int	i;

	i = 0;
	all_set = true;
	while (args[i] != NULL)
	{
		new = create_variable(args[i]);
		if (is_valid_identifier(new->name, EXPORT))
		{
			check_assignment_variables(new->name);
			add_variable(&variables->env, new);
		}
		else
		{
			all_set = false;
			free(new->name);
			free(new->value);
			free(new);
		}
		i++;
	}
	if (all_set == false)
		return (1);
	return (0);
}
