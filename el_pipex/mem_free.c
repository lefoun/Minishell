/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 17:17:12 by nammari           #+#    #+#             */
/*   Updated: 2021/08/02 17:28:11 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	{
		close(commands->input_fd);
		commands->input_fd = -1;
	}
	if (commands->output_fd != -1)
	{
		close(commands->output_fd);
		commands->output_fd = -1;
	}
	return (-1);
}

void	double_free(char *tab, char *tab2)
{
	free(tab);
	free(tab2);
}
