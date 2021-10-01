/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/30 21:50:47 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Create boolean function for function pointer
** bool	get_
*/

/*
** Add linked list related functions

t_token	*ft_create_element(t_token **head, char *arg, int index)
{

}

*/

int	main(void)
{
	char *cmd;
	// Add readline here
	cmd = readline("# pepe_shell $>");
	printf("command received: |%s|\n", cmd);
	ft_parser(cmd);
	free(cmd);
	return (0);
}

/*
** [ DEPRECATED ]
**

bool	is_operator(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == '&')
		return (true);
	return (false);
	// if (*str == '&' && *(str + 1) != '&')
	// 	return (false);
	// else
	// 	return (true);
}

*/
