/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_memory.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:45:52 by nammari           #+#    #+#             */
/*   Updated: 2021/12/08 21:53:30 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"

int	mem_free(char **tab, int index, t_command_vars *commands)
{
	while (tab && tab[index])
	{
		free(tab[index]);
		++index;
	}
	if (tab)
		free(tab);
	tab = NULL;
	if (commands->input_fd != -1)
		close(commands->input_fd);
	if (commands->output_fd != -1)
		close(commands->output_fd);
	return (g_variables->last_exit_status);
}

void	double_free(char *tab, char *tab2)
{
	free(tab);
	free(tab2);
}
