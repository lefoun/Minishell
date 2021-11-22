/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stone <stone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:56 by sdummett          #+#    #+#             */
/*   Updated: 2021/11/22 18:34:42 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//
// IMPORTANT: Change strcmp to ft_strcmp
//

static void	delete_variable(t_variable **head, char *varname_to_del)
{
	unsigned int	len;
	t_variable		*env;
	t_variable		*previous;

	env = *head;
	previous = NULL;
	while (env != NULL)
	{
		len = get_greatest_len(env->name, varname_to_del);
		if (ft_strncmp(env->name, varname_to_del, len) == 0)
		{
			if (previous == NULL)
				*head = env->next;
			else
				previous->next = env->next;
			free(env->name);
			free(env->value);
			free(env);
			return ;
		}
		previous = env;
		env = env->next;
	}
}

int	ft_unset(char **args)
{
	bool			all_unset;
	unsigned int	i;

	i = 0;
	all_unset = true;
	while (args[i] != NULL)
	{
		if (is_valid_identifier(args[i], UNSET))
			delete_variable(&variables->env, args[i]);
		else
			all_unset = false;
		i++;
	}
	if (all_unset == false)
		return (1);
	return (0);
}
