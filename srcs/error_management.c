/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:38:04 by nammari           #+#    #+#             */
/*   Updated: 2021/10/06 18:30:13 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void	ft_catch_error(bool error_check, int error_cause, char *str, t_token **head)
{
	return ;
	(void)head;
	if (error_check == false)
		return ;
	if (error_cause == MALLOC_ERROR)
	{
		perror("Error ! Malloc Failed.\n");
	}
	else if (error_cause == CMD_NOT_FOUND)
	{
		perror("Error ! command doesn't exist");
	}
	free(str);
	exit(1);
}

int	ft_free_tab(char **tab, int error_cause)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			++i;
		}
		free(tab);
	}
	return (error_cause);
}