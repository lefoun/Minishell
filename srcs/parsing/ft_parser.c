/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:30:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/11 17:56:18 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_prosseced_cmd_line(char *cmd)
{
	
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
