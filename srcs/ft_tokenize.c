/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:33:37 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/04 16:13:59 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token *ft_tokenize(char *cmd)
{
	t_token	*head;
	char	**splited_arguments;
	int		i;
	int		j;
	(void)head;
	(void)splited_arguments;
	// return (NULL);

	i = 0;
	head = NULL;
	while (cmd[i])
	{
	// Add args to get_next_type_operator call
	// i = get_next_type_operator();
		// Add function
		//create_op_element();
		if (is_operator(cmd[i]))
		{
			j = get_redir_out_trunc(cmd + i, 0, &head);
			printf("This is the return value %d and Type %d and content %s\n", j, head->type, head->value);
		}
		++i;
		// j = 0;
		// while (!is_space(*cmd))
		// 	++j;
	}
	return (NULL);
}
