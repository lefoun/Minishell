/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:30:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/12 16:57:39 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_alpha_num(char c)
{
	if (c >= 42 && c <= 126)
		return (true);
	return (false);
}

int	skip_double_quotes(char *cmd_line, int *index)
{
	if (cmd_line[*index] != '"')
		return (1);
	while (cmd_line[*index] != '\0')
	{
		++(*index);
		if (cmd_line[*index] == '"')
		{
			++(*index);
			return (0);
		}
	}
	return (ERROR);
}

int	skip_single_quotes(char *cmd_line, int *index)
{
	if (cmd_line[*index] != '\'')
		return (1);
	while (cmd_line[*index] != '\0')
	{
		++(*index);
		if (cmd_line[*index] == '\'')
		{
			++(*index);
			return (0);
		}
	}
	return (ERROR);
}

int	count_word_nb(char *cmd_line)
{
	int		i;
	int		wrd_count;

	i = 0;
	wrd_count = 0;
	while (cmd_line[i] != '\0')
	{
		while (is_whitespace(cmd_line[i]))
			++i;
		while (is_alpha_num(cmd_line[i]) && !is_operator(cmd_line[i]))
			++i;
		if (skip_double_quotes(cmd_line, &i) == ERROR ||
			skip_single_quotes(cmd_line, &i) == ERROR)
				return (ERROR);
		++wrd_count;
		while (is_operator(cmd_line[i]))
			++i;
	}
	return (wrd_count);
}

// char	**get_prosseced_cmd_line(char *cmd_line)
// {
// 	int		i;
// 	char	**splited_args;

// 	i = 0;
	
	
// }

int	ft_parser(char *cmd)
{
	t_ast	*root;
	t_token *head;

	head = ft_tokenize(cmd, &head);
	if (!head)
		return (-1);
	root = ft_create_ast(cmd);
	if (!root)
		return (-1);
	return (0);
}
