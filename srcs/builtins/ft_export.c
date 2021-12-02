/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:49 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/02 21:36:54 by sdummett         ###   ########.fr       */
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
	if (str[len] == '=')
		len++;
	else
		return (NULL);
	name = malloc(sizeof(char) * len + 1);
	if (name == NULL)
		return (NULL);
	len = 0;
	while (str[len] != '=')
	{
		name[len] = str[len];
		len++;
	}
	name[len] = '\0';
	return (name);
}

static void	update_env(char *name, char *new_var)
{
	unsigned int	i;
	unsigned int	name_len;

	i = 0;
	if(getenv(name) == NULL)
	{
		while (variables->envp[i] != NULL)
			i++;
		variables->envp[i] = ft_strdup(new_var);
		variables->envp[i + 1] = NULL;
	}
	else
	{
		name_len = ft_strlen(name);
		while (variables->envp[i] != NULL)
		{
			if (ft_strncmp(variables->envp[i], name, name_len) == 0)
				variables->envp[i] = ft_strdup(new_var);
			i++;
		}
	}
}

int	ft_export(char **args)
{
	//t_variable		*new;
	char			*name;
	bool			all_set;
	unsigned int	i;

	i = 0;
	all_set = true;
	while (args[i] != NULL)
	{
		name = get_variable_name(args[i]);
		if (is_valid_identifier(name, EXPORT))
		{
			update_env(name, args[i]);
		}
		else
		{
			// free(new->name);
			// free(new->value);
			// free(new);
			all_set = false;
		}
		free(name);
		i++;
	}
	if (all_set == false)
		return (1);
	return (0);
}

// static char	*get_variable_value(char *str)
// {
// 	int		len;
// 	char	*value;

// 	while (*str != '=' && *str != '\0')
// 		str++;
// 	if (*str == '=')
// 		str++;
// 	len = ft_strlen(str);
// 	value = malloc(sizeof(char) * len + 1);
// 	if (value == NULL)
// 		return (NULL);
// 	if (len == 0)
// 		value[0] = '\0';
// 	else
// 	{
// 		len = 0;
// 		while (str[len] != '\0')
// 		{
// 			value[len] = str[len];
// 			len++;
// 		}
// 		value[len] = '\0';
// 	}
// 	return (value);
// }

// static t_variable	*create_variable(char *str)
// {
// 	t_variable	*new;

// 	new = malloc(sizeof(t_variable));
// 	if (new == NULL)
// 		return (NULL);
// 	new->name = get_variable_name(str);
// 	new->value = get_variable_value(str);
// 	new->next = NULL;
// 	return (new);
// }
