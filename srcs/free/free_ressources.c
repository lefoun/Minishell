/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_ressources.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 14:57:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/05 15:12:36 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	free(variables);
}
