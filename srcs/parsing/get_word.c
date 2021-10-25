/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_word.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:58:22 by nammari           #+#    #+#             */
/*   Updated: 2021/10/25 16:02:15 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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