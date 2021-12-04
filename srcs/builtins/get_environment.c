/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_environment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 09:23:23 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/04 10:13:41 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**init_env_tab(void)
{
	unsigned int	len;
	t_variable		*tmp;
	char			**env;

	len = 0;
	tmp = variables->env;
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	env = malloc(sizeof(char *) * (len + 1));
	if (env == NULL)
		return (NULL);
	return (env);
}

static char	*get_full_variable(t_variable *var)
{
	unsigned int	len;
	char			*new;

	len = ft_strlen(var->name) + ft_strlen(var->value) + 2;
	new = malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, var->name, len);
	ft_strlcat(new, "=", len);
	ft_strlcat(new, var->value, len);
	return (new);
}

char	**get_environment(void)
{
	unsigned int	i;
	t_variable		*tmp;
	char			**env;

	env = init_env_tab();
	i = 0;
	tmp = variables->env;
	while (tmp != NULL)
	{
		env[i] = get_full_variable(tmp);
		i++;
		tmp = tmp->next;
	}
	env[i] = NULL;
	return (env);
}
