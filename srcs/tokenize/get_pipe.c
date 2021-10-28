/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:37:47 by nammari           #+#    #+#             */
/*   Updated: 2021/10/28 14:51:08 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_pipe_op(char **args, int index, t_token **head)
{
	char	*content;
	int		ret;

	if (index == 0 || (args[index + 1] && is_operator(args[index + 1][0])))
	{
		if (args[index + 1] != NULL && args[index + 1][0] == '|')
			ft_putstr_fd("pepe_shell: "
					"syntax error near unexpected token `||\'\n", 2);
		else if (index == 0)
			ft_putstr_fd("pepe_shell: "
					"syntax error near unexpected token `|\'\n", 2);
		else
			ft_putstr_fd("pepe_shell: syntax error near"
					" unexpected token `newline\'\n", 2);
		return (3);
	}
	content = ft_strdup("|");
	ret = ft_elem_pushback(head, ft_create_elem(content, PIPE));
	ft_catch_error(ret == 2, content, head);
	return (0);
}
