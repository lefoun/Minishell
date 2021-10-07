/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_next_assignment.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:52:06 by nammari           #+#    #+#             */
/*   Updated: 2021/10/07 14:54:04 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_next_word_assignment(char *cmd_line)
{
	int	i;

	i = 0;
	while (!is_whitespace(cmd_line[i]) && cmd_line[i] != '\0')
	{
		if (cmd_line[i] == '=')
			return (true);
		i++;
	}
	return (false);
	
}
