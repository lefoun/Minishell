/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cmd_name_suffix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:21:05 by nammari           #+#    #+#             */
/*   Updated: 2021/10/15 16:52:58 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int get_cmd(char *str, t_token **head)
{
	int		i;
	int		j;
	int		ret;
	char	*cmd;

	if (is_operator(*str))
		return (1);
	i = 0;
	while (is_whitespace(str[i]))
		++i;
	j = 0;
	while (str[i + j])
		++j;
	cmd = ft_strdup_index(str + i, j);
	ret = ft_elem_pushback(head, ft_create_elem(cmd, CMD_NAME));
	if (ft_catch_error(ret == 2, cmd, head) == MALLOC_ERROR)
		return (1);
	return (0);
}
