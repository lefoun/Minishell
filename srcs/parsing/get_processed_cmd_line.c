/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_processed_cmd_line.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 13:53:52 by nammari           #+#    #+#             */
/*   Updated: 2021/10/15 13:54:48 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	split_cmd_line(cmd_line, splited_args, words_nb);
	while (i < words_nb)
	{
		printf("This is word n#_%0d/%0d: |%s|\n", i, words_nb, splited_args[i]);
		++i;
	}
	return (splited_args);
}