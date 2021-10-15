/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:33:37 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/15 16:51:49 by nammari          ###   ########.fr       */
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

void	ft_init_function_pointer(int (*get_operators[])(char *, t_token **))
{
	get_operators[0] = get_redir_out_append;
	get_operators[1] = get_redir_out_trunc;
	get_operators[2] = get_redir_input_file;
	get_operators[3] = get_redir_input_here_doc;
	get_operators[4] = get_pipe_op;
	get_operators[5] = get_and_op;
	get_operators[6] = get_or_op;
}

int	find_type_cmd_name_or_assign(char *str)
{
	while (*str && !is_operator(*str))
	{
		if (*str == '=')
			return (1);
	}
	return (0);
}

void	ft_new_tokenize(char **args, t_token **head)
{
	int	i;
	int	j;

	i = 0;
	*head = NULL;
	int	(*get_operators[7])(char *arg, t_token **head);
	ft_init_function_pointer(get_operators);
	while (args && args[i])
	{
		j = 0;
		if (is_operator(args[i][0]))
			while (j < 7 && (*get_operators[j])(args[i], head) != 0)
				++j;
		else if (is_next_word_assignment(args[i]))
			get_assignment(args[i], head);
		else
		{
			get_cmd(args[i], head);
			while (args[++i] && !is_operator(args[i][0]))
				get_cmd_suffix(args[i], head);
		}
		if (args[i])
			++i;
	}
	print_token(*head);
}


t_token *ft_tokenize(char *cmd, t_token **head)
{
	int		i;
	int		j;
	int		ret;
	bool	redirection;
	char	prefix_op;

	i = 0;
	*head = NULL;
	redirection = false;
	prefix_op = '0';
	int	(*get_operators[7])(char *arg, t_token **head);
	ft_init_function_pointer(get_operators);
	while (cmd[i])
	{
		while (is_whitespace(cmd[i]))
			i++;
		if (is_next_word_assignment(cmd + i))
		{
			ret = get_assignment(cmd + i, head);
			ft_catch_error(ret == 2, NULL, head);
			while (cmd[i] != '\0' && !is_operator(cmd[i]) && !is_whitespace(cmd[i]))
				i++;
		}
		else
		{
			ret = get_cmd(cmd + i, head);
			if (ft_catch_error(ret == 2, NULL, head) == MALLOC_ERROR)
				return (NULL);
			while (cmd[i] != '\0' && !is_operator(cmd[i]))
				i++;
		}
		if (cmd[i] == '<' || cmd[i] == '>')
			redirection = true;
		
		if (is_operator(cmd[i]))
		{
			prefix_op = cmd[i];
			j = 0;
			while ((*get_operators[j])(cmd + i , head) != 0 && j < 7)
				++j;
		}
		//add a function that checks if we have false operators like >>>
		while (is_operator(cmd[i]))
			++i;
		while (is_whitespace(cmd[i]))
			++i;
		if (redirection == true)
			while (cmd[i] != '\0' && !is_operator(cmd[i]) && !is_whitespace(cmd[i]))
				++i;
		redirection = false;
	}
	print_token(*head);
	return (*head);
}
