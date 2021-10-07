/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:33:37 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/07 11:31:23 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token(t_token *head)
{
	while (head)
	{
		printf("type : %d | value : %s\n", head->type, head->value);
		head = head->next;
	}
}

void	ft_init_function_pointer(int (*get_operators[])(char *, t_token **))
{
	get_operators[0] = get_redir_out_append;
	get_operators[1] = get_redir_out_trunc;
	get_operators[2] = get_redir_input_file;
	get_operators[3] = get_redir_input_here_doc;
	get_operators[4] = get_pipe_op;
}

t_token *ft_tokenize(char *cmd)
{
	t_token	*head;
	int		i;
	int		j;
	bool	redirection;
	char	prefix_op;
	
	i = 0;
	head = NULL;
	redirection = false;
	prefix_op = '0';
	ft_init_function_pointer(get_operators);
	while (cmd[i])
	{
		while (is_whitespace(cmd[i]))
			i++;
		int ret = get_cmd(cmd + i, &head);
		ft_catch_error(ret == 2, MALLOC_ERROR, NULL, &head);
		while (cmd[i] != '\0' && !is_operator(cmd[i]))
			i++;
		if (cmd[i] == '<' || cmd[i] == '>')
			redirection = true;
		if (is_operator(cmd[i]))
		{
			prefix_op = cmd[i];
			j = 0;
			while ((*get_operators[j])(cmd + i , &head) != 0 && j < 5)
				++j;
			// printf("This is the return value %d and Type %d and content %s\n", j, head->type, head->value);
		}
		while (is_operator(cmd[i]))
			++i;
		while (is_whitespace(cmd[i]))
			++i;
		if (redirection == true)
			while (cmd[i] != '\0' && !is_operator(cmd[i]) && !is_whitespace(cmd[i]))
				++i;
		redirection = false;
	}
	print_token(head);
	return (NULL);
}
