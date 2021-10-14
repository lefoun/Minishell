/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:30:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/14 16:36:32 by nammari          ###   ########.fr       */
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
	if (is_operator(cmd_line[*index]))
		++*word_count;
	while (is_operator(cmd_line[*index]))
	{
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

char	*get_word(char *cmd_line, int word_length)
{
	int		i;
	char	*word;

	i = 0;
	word = malloc(sizeof(*word) * (word_length + 1));
	if (word == NULL)
		return (NULL);
	word[word_length] = '\0';
	while (word_length--)
	{
		--cmd_line;
		word[word_length] = *cmd_line;
	}
	return (word);
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

void	skip_operator_and_increment(char *cmd_line, int *i, int *j)
{
	while (is_operator(cmd_line[*i]))
	{
		++*i;
		++*j;
	}
}

void	increment_i_and_j(int *i, int *j)
{
	++*i;
	++*j;
}

void	copy_words_from_cmd_line(char *cmd_line, char **args, int words_nb)
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

char	**get_prosseced_cmd_line(char *cmd_line)
{
	int		i;
	int		words_nb;
	char	**splited_args;

	i = 0;
	words_nb = count_words_nb(cmd_line);
	if (words_nb == ERROR)
		return (NULL);
	splited_args = malloc(sizeof(*splited_args) * (words_nb + 1));
	if (splited_args == NULL)
		return (NULL);
	copy_words_from_cmd_line(cmd_line, splited_args, words_nb);
	while (i < words_nb)
	{
		printf("This is word n#_%0d/%0d: |%s|\n", i, words_nb, splited_args[i]);
		++i;
	}
	return (splited_args);
}

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
