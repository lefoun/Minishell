/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:55:21 by nammari           #+#    #+#             */
/*   Updated: 2021/10/25 17:09:05 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

///////////////////////

t_variable	*create_variable(char *name, char *value)
{
	t_variable	*new;

	new = malloc(sizeof(t_variable));
	if (new == NULL)
		return (NULL);
	new->name = name;
	if (value == NULL)
		new->value = NULL;
	else
		new->value = value;
	new->next = NULL;
	return (new);
}

static void	change_variable_value(t_variable *env, t_variable *new)
{
	if (env->value != NULL)
		free(env->value);
	env->value = new->value;
	free(new->name);
	free(new);
}

void	add_variable(t_variable **head, t_variable *new)
{
	t_variable	*env;

	if (*head == NULL)
		*head = new;
	else
	{
		env = *head;
		while (env != NULL)
		{
			if (strcmp(env->name, new->name) == 0)
			{
				change_variable_value(env, new);
				break ;
			}
			if (env->next == NULL)
			{
				env->next = new;
				break ;
			}
			env = env->next;
		}
	}
}
//////////////////


void	increment_i_and_j(int *i, int *j)
{
	++*i;
	++*j;
}

void	skip_operator_and_increment(char *cmd_line, int *i, int *j)
{
	char	operator;
	if (cmd_line[*i] == '$')
	{
		while (cmd_line[*i] != '\0' && !is_whitespace(*cmd_line))
		{
			++*i;
			++*j;
		}
		return ;
	}
	operator = cmd_line[*i];
	++*i;
	++*j;
	if (cmd_line[*i] == operator)
	{
		++*i;
		++*j;
	}
}

char	*search_dollar_word(char *word)
{
	int		i;
	int		j;
	char	*dollar_word;

	i = 0;
	j = 0;
	while (word[i] != '\0' && word[i] != '$')
		++i;
	if (word[i] == '\0')
		return (NULL);
	++i;
	while (!is_whitespace(word[i + j]) && word[i + j] != '\0' &&
		word[i + j] != '$')
			++j;
	dollar_word = malloc(sizeof(*dollar_word) * j + 1);
	if (dollar_word == NULL)
		return (NULL);
	dollar_word[j] = '\0';
	while (j-- > 0)
		dollar_word[j] = word[i + j];	
	return (dollar_word);
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

void	copy_word(char *word, char *new_wrd, char *dlr_wrd, char *dlr_value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (word[i] != '\0' && word[i] != '$')
	{
		new_wrd[j] = word[i];
		++j;
		++i;
	}
	// dprintf(2, "here1\n");
	if (word[i] == '$')
		++i;
	i = i + ft_strlen(dlr_wrd);
	// dprintf(2, "here2\n");
	while (dlr_value && *dlr_value)
	{
		new_wrd[j++] = *dlr_value;
		++dlr_value;
	}
	// dprintf(2, "here3\n");
	while (word[i] != '\0')
	{
		new_wrd[j++] = word[i];
		++i;
	}
	new_wrd[j] = '\0';
	// dprintf(2, "here4\n");
}

char	*get_dollar_word_value(t_vars *vars, char *dollar_word)
{
	while (vars->env)
	{
		if (ft_strcmp(vars->env->name, dollar_word) == 0)
			return (vars->env->value);
		// dprintf(2, "This is dollr_word |%s| and |%s|\n", dollar_word, vars->env->name);
		vars->env = vars->env->next;
	}
	while (vars->global)
	{
		if (ft_strcmp(vars->global->name, dollar_word) == 0)
			return (vars->global->value);
		vars->global = vars->global->next;
	}
	return (NULL);
}

char	*replace_dollar_word(char *word, char *dollar_word, t_vars *vars)
{
	int		i;
	int		j;
	long	len;
	char	*new_wrd;
	char	*dlr_wrd_value;

	i = 0;
	j = 0;
	dlr_wrd_value = get_dollar_word_value(vars, dollar_word);
	len = ft_strlen(word) - ft_strlen(dollar_word) + ft_strlen(dlr_wrd_value);
	new_wrd = malloc(sizeof(*new_wrd) * len + 1);
	if (new_wrd == NULL)
		return (NULL);
	copy_word(word, new_wrd, dollar_word, dlr_wrd_value);
	free(dollar_word);
	free(word);
	return (new_wrd);
}

char	*get_between_quotes_word(char *cmd_line, int *new_index, t_vars *vars)
{
	int		i;
	int		j;
	char	*word;
	char	*dollar_word;

	i = 0;
	j = 0;
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
		if (word[i] != '\0')
			++i;
	}
	return (word);
}

char	*get_woord(char *cmd_line, int word_length, t_vars *vars)
{
	int		i;
	char	*word;
	char	*dollar;

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
	dollar = search_dollar_word(word);
	if (dollar != NULL)
	{
		word = replace_dollar_word(word, dollar, vars);
		// dprintf(2, "This is the index |%d|\n",*index);
		// dprintf(2, "This is the input %d and -> |%s|\n",*index,  cmd_line + *index);
		return (word);
	}
	return (word);
}

void	split_cmd_line(char *cmd_line, char **args, int words_nb, t_vars *vars)
{
	int		i;
	int		j;
	int		k;
	(void)vars;
	t_vars	*variable;

	variable = malloc(sizeof(*variable));
	variable->env = create_variable("hello", "var_value");
	variable->env->next = create_variable("stony", "lalalala");
	variable->global = NULL;
	// dprintf(2, "This is vars-env-name |%s|\n", vars->env->name);
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
			args[k++] = get_woord(cmd_line + i, j, variable);
		else if (is_quote(cmd_line[i]))
		{
			args[k++] = get_between_quotes_word(cmd_line + i, &i, variable);
		}
		else
		{
			skip_operator_and_increment(cmd_line, &i, &j);
			if (j > 0)
				args[k++] = get_woord(cmd_line + i, j, variable);
		}
	}
	args[words_nb] = NULL;
}