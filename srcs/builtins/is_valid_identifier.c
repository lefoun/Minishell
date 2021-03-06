/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:06:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/09 10:38:53 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(char *str, int builtin)
{
	if (builtin == UNSET || builtin == ASSIGNMENT)
		return ;
	if (builtin == EXPORT)
	{
		write(2, g_variables->prog_name, ft_strlen(g_variables->prog_name));
		write(2, ": export: ", ft_strlen(": export: "));
	}
	write(2, str, ft_strlen(str));
	write(2, ": not a valid identifier\n",
		ft_strlen(": not a valid identifier\n"));
}

bool	is_valid_identifier(char *str, int builtin)
{
	unsigned int	i;

	if (str == NULL)
		return (false);
	if (str[0] >= '0' && str[0] <= '9')
	{
		print_error(str, builtin);
		return (false);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || \
			(str[i] >= 'a' && str[i] <= 'z') || \
			(str[i] >= '0' && str[i] <= '9') || \
			str[i] == '_')
			i++;
		else
		{
			print_error(str, builtin);
			return (false);
		}
	}
	return (true);
}
