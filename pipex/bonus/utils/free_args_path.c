/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_args_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stone <stone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 18:18:54 by stone             #+#    #+#             */
/*   Updated: 2021/08/12 18:20:55 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_tab(char **ptr)
{
	int		i;

	i = 0;
	while (ptr[i] != NULL)
	{
		printf("|%s|\n", ptr[i]);
		free(ptr[i]);
		ptr[i] = NULL;
		i++;
	}
	free(ptr);
	ptr = NULL;
}

void	free_args_path(char **args, char **path)
{
	free_tab(args);
	free_tab(path);
}
