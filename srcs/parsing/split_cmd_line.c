/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stone <stone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:55:21 by nammari           #+#    #+#             */
/*   Updated: 2021/12/01 15:33:01 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	increment_i_and_j(int *i, int *j)
{
	++*i;
	++*j;
}

bool	skip_operator_and_increment(char *cmd_line, int *i, int *j)
{
	char	operator;
	
	if (cmd_line[*i] == '$')
	{
		increment_i_and_j(i, j);
		while (cmd_line[*i] != '\0' && !is_whitespace(cmd_line[*i]))
			increment_i_and_j(i, j);
		return (true);
	}
	else if (is_operator(cmd_line[*i]))
	{
		operator = cmd_line[*i];
		increment_i_and_j(i, j);
		if (cmd_line[*i] == operator && operator != '|')
			increment_i_and_j(i, j);
		return (true);	
	}
	return (false);
}

char	*get_word_without_quotes(char *cmd_line, int *new_index)
{
	int		i;
	int		j;
	char	*word;
	char	quote_type;

	i = 0;
	j = 0;
	quote_type = cmd_line[i];
	cmd_line++;
	while(cmd_line[i] != '\0' && cmd_line[i] != quote_type)
		++i;
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	while (j < i)
	{
		word[j] = cmd_line[j];
		++j;
	}
	word[j] = '\0';
	*new_index = *new_index + j + 2;
	return (word);
}

char	*get_between_quotes_word(char *cmd_line, int *new_index, t_vars *vars)
{
	int		i;
	char	*word;
	char	*dollar_word;

	i = 0;
	word = get_word_without_quotes(cmd_line, new_index);
	if (*cmd_line == '\'')
		return (word);
	while (word[i])
	{
		dollar_word = search_dollar_word(word + i);
		if (dollar_word == NULL)
			return (word);
		word = replace_dollar_word(word, dollar_word, vars);
		if (word == NULL)
			return (NULL);
		while (word[i] != '\0' && word[i] != '$')
			++i;
	}
	return (word);
}

void	split_cmd_line(char *cmd_line, char **args, int words_nb, t_vars *vars)
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
			args[k++] = get_word(cmd_line + i, j, vars);
		else if (is_quote(cmd_line[i]))
			args[k++] = get_between_quotes_word(cmd_line + i, &i, vars);
		else
			if (skip_operator_and_increment(cmd_line, &i, &j))
				args[k++] = get_word(cmd_line + i, j, vars);
	}
	args[words_nb] = NULL;
}