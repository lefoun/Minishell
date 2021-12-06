/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:57:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/06 15:04:29 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_environ(char **tofree)
{
	unsigned int	i;

	i = 0;
	while (tofree[i] != NULL)
	{
		free(tofree[i]);
		i++;
	}
	free(tofree);
}

static void	free_t_variable_struct(t_variable *tofree)
{
	t_variable	*next_link;

	// if (tofree != NULL)
	// 	next_link = tofree->next;
	while (tofree != NULL)
	{
		next_link =  tofree->next;
		free(tofree->name);
		free(tofree->value);
		free(tofree);
		tofree = next_link;
	}
}

void	free_ressources(void)
{
	//t_variable	*tmp;

	free_t_variable_struct(variables->env);
	free_t_variable_struct(variables->global);
	free(variables->last_cmd_word);
	free(variables);
	rl_clear_history();
}
