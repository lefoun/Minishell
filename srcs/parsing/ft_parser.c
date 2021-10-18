/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:30:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/18 11:11:14 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token(t_token *head)
{
	char *tab[13];

	tab[0] = "CMD_NAME";
	tab[1] = "CMD_SUFFIX";
	tab[2] = "AND";
	tab[3] = "OR";
	tab[4] = "PIPE";
	tab[5] = "VAR";
	tab[6] = "REDIR_IN";
	tab[7] = "REDIR_HERE_DOC";
	tab[8] = "REDIR_OUT_TRUNC";
	tab[9] = "REDIR_OUT_APPEND";
	tab[10] = "FILE_NAME";
	tab[11] = "WILDCARD";
	tab[12] = "ASSIGN";
	while (head)
	{
		printf("type : %s | value : %s\n", tab[head->type], head->value);
		head = head->next;
	}
}

int	ft_parser(char *cmd)
{
	// t_ast	*root;
	t_token *head;
	char	**args;

	head = NULL;
	args = get_prosseced_cmd_line(cmd);
	// ft_tokenize(args, &head);
	ft_new_tokenize(args, &head);
	if (!head)
		return (-1);
	print_token(head);
	// root = ft_create_ast(cmd);
	// if (!root)
	// 	return (-1);
	return (0);
}
