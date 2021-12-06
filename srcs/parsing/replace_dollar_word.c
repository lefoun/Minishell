/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_dollar_word.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:31:19 by nammari           #+#    #+#             */
/*   Updated: 2021/12/06 13:02:18 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (word[i] == '$')
		++i;
	i = i + ft_strlen(dlr_wrd);
	while (dlr_value && *dlr_value)
	{
		new_wrd[j++] = *dlr_value;
		++dlr_value;
	}
	while (word[i] != '\0')
	{
		new_wrd[j++] = word[i];
		++i;
	}
	new_wrd[j] = '\0';
}

char	*get_dollar_word_value(char *dollar_word)
{
	t_variable	*env_var;
	t_variable	*global_var;
	
	env_var = variables->env;
	global_var = variables->global;
	while (env_var)
	{
		if (ft_strcmp(env_var->name, dollar_word) == 0)
			return (env_var->value);
		env_var = env_var->next;
	}
	while (global_var)
	{
		if (ft_strcmp(global_var->name, dollar_word) == 0)
			return (global_var->value);
		global_var = global_var->next;
	}
	return (NULL);
}

char	*replace_dollar_word(char *word, char *dollar_word)
{
	long	len;
	char	*new_wrd;
	char	*dlr_wrd_value;

	if (ft_strcmp(dollar_word, "?") == 0)
		dlr_wrd_value = ft_itoa(variables->last_exit_status);
	else
		dlr_wrd_value = get_dollar_word_value(dollar_word);
	len = ft_strlen(word) - ft_strlen(dollar_word) + ft_strlen(dlr_wrd_value);
	new_wrd = malloc(sizeof(*new_wrd) * len + 1);
	if (new_wrd == NULL)
		return (NULL);
	copy_word(word, new_wrd, dollar_word, dlr_wrd_value);
	free(dollar_word);
	free(word);
	return (new_wrd);
}
