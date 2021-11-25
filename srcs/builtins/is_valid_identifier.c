/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_identifier.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stone <stone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 19:06:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/11/22 18:16:05 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_error(char *str, int builtin)
{
	if (builtin == EXPORT)
		write(2, "minishell: export: ", 19);
	else if (builtin == UNSET)
		write(2, "minishell: unset: ", 18);
	write(2, str, ft_strlen(str));
	write(2, ": not a valid identifier\n", 25);
}

bool	is_valid_identifier(char *str, int builtin)
{
	unsigned int	i;

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
		{
			i++;
		}
		else
		{
			printf("THE ERROR IS >%c<\n", str[i]);
			print_error(str, builtin);
			return (false);
		}
	}
	return (true);
}