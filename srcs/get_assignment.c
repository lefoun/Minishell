/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_assignment.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 14:37:31 by nammari           #+#    #+#             */
/*   Updated: 2021/10/07 14:55:39 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int get_assignment(char *cmd_line, t_token **head)
{
	char	*assignment;
	int		return_code;
	int		i;
	(void)return_code;
	
	i = 0;
	while (cmd_line[i] != '\0' && !is_whitespace(cmd_line[i]))
		i++;
	assignment = ft_strdup_index(cmd_line, i);
	ft_catch_error(assignment == NULL, MALLOC_ERROR, NULL, head);
	ft_elem_pushback(head, ft_create_elem(assignment, ASSIGN));
	return (0);
}