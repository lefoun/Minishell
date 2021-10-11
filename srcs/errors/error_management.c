/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:38:04 by nammari           #+#    #+#             */
/*   Updated: 2021/10/11 18:14:19 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	ft_catch_error(bool error_check, char *str, t_token **head)
{
	if (error_check == true)
	{
		perror("minishell: Error ! Malloc Failed.\n");
		free(str);
		if (head != NULL)
			free_token_lst(*head);
		return (MALLOC_ERROR);
	}
	return (0);
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
