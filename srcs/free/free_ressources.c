/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:57:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/09 10:36:54 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_link(t_variable *tofree)
{
	free(tofree->name);
	free(tofree->value);
	free(tofree);
}

void	free_assign(t_token **head)
{
	t_token	*tmp;

	tmp = *head;
	while (*head != NULL && (*head)->type == ASSIGN)
	{
		tmp = tmp->next;
		free((*head)->value);
		free(*head);
		*head = tmp;
	}
}

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

	while (tofree != NULL)
	{
		next_link = tofree->next;
		free(tofree->name);
		free(tofree->value);
		free(tofree);
		tofree = next_link;
	}
}

void	free_ressources(void)
{
	free_t_variable_struct(g_variables->env);
	free_t_variable_struct(g_variables->global);
	free(g_variables->last_cmd_word);
	free(g_variables);
	rl_clear_history();
}
