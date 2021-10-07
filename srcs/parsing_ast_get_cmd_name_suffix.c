/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ast_get_cmd_name_suffix.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 18:21:05 by nammari           #+#    #+#             */
/*   Updated: 2021/10/07 14:23:22 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_cmd_suffix(char *str, t_token **head)
{
	char	*cmd_suffix;
	int		i;
	int		j;
	int		ret;

	i = 0;
	j = 0;
	while (*str && is_whitespace(str[i]))
		++str;
	while (str[i] != '\0' && !is_operator(str[i]))
		++i;
	while (j < i)
	{
		if (!is_whitespace(str[j]))
			break ;
		++j;
	}
	if (i == j)
		return (1);
	cmd_suffix = malloc((i + 1) * sizeof(char));
	ft_catch_error(cmd_suffix == NULL, MALLOC_ERROR, cmd_suffix, head);
	while (j < i)
	{
		cmd_suffix[j] = str[j];
		++j;
	}
	cmd_suffix[j] = '\0';
	ret = ft_elem_pushback(head, ft_create_elem(cmd_suffix, CMD_SUFFIX));
	ft_catch_error(ret == 2, MALLOC_ERROR, cmd_suffix, head);
	return (0);
}



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
	while ((str[i + j] && !is_whitespace(str[i + j]) && !is_operator(str[i])))
		++j;
	cmd = ft_strdup_index(str + i, j);
	ret = ft_elem_pushback(head, ft_create_elem(cmd, CMD_NAME));
	ft_catch_error(ret == 2, MALLOC_ERROR, cmd, head);
	ret = get_cmd_suffix(str + i + j, head);
	return (ret);
}

