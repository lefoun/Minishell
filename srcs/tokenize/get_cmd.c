/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:21:05 by nammari           #+#    #+#             */
/*   Updated: 2021/12/03 21:33:45 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_cmd(char **args, int *index, t_token **head)
{
	int		ret;
	char	*cmd;

	cmd = ft_strdup(args[*index]);
	ret = ft_elem_pushback(head, ft_create_elem(cmd, CMD_NAME));
	if (ft_catch_error(ret == 2, cmd, head) == MALLOC_ERROR)
		return (1);
	if (args[*index] && args[*index + 1] && !is_operator(args[*index + 1][0]))
	{
		while (args[++*index] && !is_operator(args[*index][0]))
			get_cmd_suffix(args[*index], head);
		--*index;
	}
	return (0);
}
