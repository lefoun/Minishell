/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_words_nb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:59:48 by nammari           #+#    #+#             */
/*   Updated: 2021/10/26 11:27:50 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	skip_quotes(char *cmd_line, int *index)
{
	char	quote_type;
	
	if (!is_quote(cmd_line[*index]))
		return (1);
	quote_type = cmd_line[*index];
	while (cmd_line[*index] != '\0')
	{
		++(*index);
		if (cmd_line[*index] == quote_type)
		{
			++(*index);
			return (0);
		}
	}
	return (ERROR);
}

void	count_and_skip_operator(char *cmd_line, int *index, int *word_count)
{
	char	c;

	if (is_operator(cmd_line[*index]))
		++*word_count;
	c = cmd_line[*index];
	++*index;
	if (is_redirection(c))
	{
		if (cmd_line[*index] == c)
			++*index;
	}
}

int	count_words_nb(char *cmd_line)
{
	int		i;
	int		wrd_count;

	i = 0;
	wrd_count = 0;
	while (cmd_line[i] != '\0')
	{
		while (is_whitespace(cmd_line[i]))
			++i;
		if (is_alpha_num(cmd_line[i]) && !is_operator(cmd_line[i]))
		{
			while (is_alpha_num(cmd_line[i]) && !is_operator(cmd_line[i]))
				++i;
			++wrd_count;
		}
		if (is_quote(cmd_line[i]))
		{
			if (skip_quotes(cmd_line, &i) == ERROR)
				return (ERROR);
			++wrd_count;
		}
		count_and_skip_operator(cmd_line, &i, &wrd_count);
	}
	return (wrd_count);
}
