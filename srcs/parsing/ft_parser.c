/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:30:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/19 12:12:59 by nammari          ###   ########.fr       */
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

int	check_if_multi_operator(char **args)
{
	int		i;
	int		j;
	int		count_in_redir;
	int		count_out_redir;

	i = 0;
	count_in_redir = 0;
	count_out_redir = 0;
	while (args[i])
	{
		j = 0;
		while (args[i][j])
		{
			if (args[i][j] == '>')
				++count_out_redir;
			if (args[i][j] == '<')
				++count_in_redir;
			++j;
		}
		if (count_in_redir > 2 || count_out_redir > 2)
			return (ERROR);
		++i;
	}
	return (0);
}

int	check_operator_errors(char **args)
{
	if (check_if_multi_operator(args) == ERROR)
		return (ERROR);
	return (0);	
}

int	check_parsing_errors(char **args)
{
	if (check_operator_errors(args) == ERROR)
		return (ERROR);
	return (0);
}

int	ft_parser(char *cmd)
{
	// t_ast	*root;
	t_token *head;
	char	**args;

	head = NULL;
	args = get_prosseced_cmd_line(cmd);
	// ft_tokenize(args, &head);
	// if (check_parsing_errors(args) == ERROR)
	// {
	// 	printf("Parsing error near redirection\n");
	// 	return (ERROR);
	// }
	ft_new_tokenize(args, &head);
	if (!head)
		return (-1);
	print_token(head);
	// root = ft_create_ast(cmd);
	// if (!root)
	// 	return (-1);
	return (0);
}
