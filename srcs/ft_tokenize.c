/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:33:37 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/06 12:19:13 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	(*func_chercher[4])(char *arg, int index, t_token **head);

t_token *ft_tokenize(char *cmd)
{
	t_token	*head;
	char	**splited_arguments;
	int		i;
	int		j;
	char	prefix_op;

	(void)splited_arguments;
	func_chercher[0] = get_redir_out_append;
	func_chercher[1] = get_redir_out_trunc;
	func_chercher[2] = get_redir_input_file;
	func_chercher[3] = get_redir_input_here_doc;

	i = 0;
	head = NULL;
	prefix_op = '0';
	while (cmd[i])
	{
	// Add args to get_next_type_operator call
	// i = get_next_type_operator();
		// Add function
		//create_op_element();
		if (is_operator(cmd[i]) && cmd[i] != prefix_op)
		{
			prefix_op = cmd[i];
			j = 0;
			while (is_operator(cmd[i]))
			{
				int k;
				k = (*func_chercher[j])(cmd + i , i, &head);
				if (k == 0)
					break ;
				++j;
			}
			printf("This is the return value %d and Type %d and content %s\n", j, head->type, head->value);
		}
		++i;
		// j = 0;
		// while (!is_space(*cmd))
		// 	++j;
	}
	return (NULL);
}