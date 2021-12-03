/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_dollar_word.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 10:30:10 by nammari           #+#    #+#             */
/*   Updated: 2021/12/03 21:25:21 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	while (!is_whitespace(word[i + j]) && word[i + j] != '\0'
		&& word[i + j] != '$' && !is_quote(word[i + j]))
			++j;
	dollar_word = malloc(sizeof(*dollar_word) * j + 1);
	if (dollar_word == NULL)
		return (NULL);
	dollar_word[j] = '\0';
	while (j-- > 0)
		dollar_word[j] = word[i + j];
	return (dollar_word);
}
