/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 17:37:47 by nammari           #+#    #+#             */
/*   Updated: 2021/10/12 15:38:06 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_pipe_op(char *str, t_token **head)
{
	char	*content;
	int		ret;

	if (*str != '|' || (*str == '|' && str[1] == '|'))
		return (1);
	content = ft_strdup("|");
	ret = ft_elem_pushback(head, ft_create_elem(content, PIPE));
	ft_catch_error(ret == 2, content, head);
	return (0);
}
