/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:30:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/15 16:34:25 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_parser(char *cmd)
{
	// t_ast	*root;
	t_token *head;
	char	**args;

	head = NULL;
	args = get_prosseced_cmd_line(cmd);
	// ft_tokenize(args, &head);
	ft_new_tokenize(args, &head);
	if (!head)
		return (-1);
	// root = ft_create_ast(cmd);
	// if (!root)
	// 	return (-1);
	return (0);
}
