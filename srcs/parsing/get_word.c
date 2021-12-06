/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:58:22 by nammari           #+#    #+#             */
/*   Updated: 2021/12/06 12:59:12 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*get_word(char *cmd_line, int word_length)
{
	char	*word;
	char	*dollar;
	int		i;

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
	while (word && word[i])
	{
		dollar = search_dollar_word(word + i);
		if (dollar == NULL)
			return (word);
		word = replace_dollar_word(word, dollar);
		while (word && word[i] != '\0' && word[i] != '$')
			++i;
	}
	return (word);
}
