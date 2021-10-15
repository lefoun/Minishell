/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:55:21 by nammari           #+#    #+#             */
/*   Updated: 2021/10/15 13:59:07 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	increment_i_and_j(int *i, int *j)
{
	++*i;
	++*j;
}

void	skip_operator_and_increment(char *cmd_line, int *i, int *j)
{
	while (is_operator(cmd_line[*i]))
	{
		++*i;
		++*j;
	}
}

char	*get_between_quotes_word(char *cmd_line, int *new_index)
{
	int		i;
	int		j;
	char	quote_type;
	char	*word;

	i = 0;
	j = 0;
	quote_type = cmd_line[i];
	cmd_line++;
	while(cmd_line[i] && cmd_line[i] != quote_type)
		++i;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	while (j < i)
	{
		word[j] = cmd_line[j];
		++j;
	}
	word[i] = '\0';
	*new_index = *new_index + j + 2;
	return (word);
}

void	split_cmd_line(char *cmd_line, char **args, int words_nb)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	while (cmd_line[i])
	{
		j = 0;
		while (is_whitespace(cmd_line[i]))
			++i;
		while (is_alpha_num(cmd_line[i]) && !is_operator(cmd_line[i]))
			increment_i_and_j(&i, &j);
		if (j > 0)
			args[k++] = get_word(cmd_line + i, j);
		else if (is_quote(cmd_line[i]))
			args[k++] = get_between_quotes_word(cmd_line + i, &i);
		else
		{
			skip_operator_and_increment(cmd_line, &i, &j);
			if (j > 0)
				args[k++] = get_word(cmd_line + i, j);
		}
	}
	args[words_nb] = NULL;
}