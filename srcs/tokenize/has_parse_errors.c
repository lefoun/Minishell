/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   has_parse_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:12:54 by nammari           #+#    #+#             */
/*   Updated: 2021/12/03 21:32:04 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	has_parse_errors(char *cmd_line)
{
	int		i;
	char	tab[3];

	(void)tab;
	i = 0;
	while (is_whitespace(cmd_line[i]))
	{
		++i;
	}
	return (false);
}

/* Types of Parsing Errors

1- 3 or more consecutive operators : exp : >>> |||| &&&&
2- Operators that follow each other with no command in between : exp ls | > &&
3- An incorrect combination of operators : exp : <> >< |< |&|
4- ...

*/