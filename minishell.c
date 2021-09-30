/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/30 21:37:56 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Create boolean function for function pointer
** bool	get_
*/

bool	is_operator(char c)
{
	if (c == '<' || c == '>')
		return (true);
	else
		return (false);
}

int	get_next_type_operator(bool (*func_chercher[6])(char *str, int index, t_token **head), \
				char *arg, int index, t_token **head)
{
	int	i;

	i = 0;
	while (arg[i] && !is_operator(arg[i]))
		++i;
	while (!func_chercher[i](arg, index, head))
	{
		++i;
		if (i == 6)
			return (-1);
	}
	return (0);
}

int	get_index_of_operator(char *arg)
{
	int	i;
	(void)arg;

	i = 0;
	return (i);
}


/*
** Add linked list related functions

t_token	*ft_create_element(t_token **head, char *arg, int index)
{

}

*/

void	get_op_elem(void)
{
	printf("I'm get_op_elem\n");
}

int	main(void)
{
	char *cmd;
	// Add readline here
	cmd = readline("# pepe_shell $>");
	printf("command received: |%s|\n", cmd);
	return (0);
	ft_parser(cmd);
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
