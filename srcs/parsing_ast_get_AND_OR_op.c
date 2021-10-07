/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_ast_get_AND_OR_op.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:45:11 by nammari           #+#    #+#             */
/*   Updated: 2021/10/07 11:57:53 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

int	get_and_op(char *str, t_token **head)
{
	char	*content;
	int		ret;

	if (!(*str == '&' && str[1] == '&'))
		return (1);
	content = ft_strdup("&&");
	ret = ft_elem_pushback(head, ft_create_elem(content, AND));
	ft_catch_error(ret == 2, MALLOC_ERROR, content, head);
	return (0);
}

int	get_or_op(char *str, t_token **head)
{
	char	*content;
	int		ret;

	if (!(*str == '|' && str[1] == '|'))
		return (1);
	content = ft_strdup("||");
	ret = ft_elem_pushback(head, ft_create_elem(content, OR));
	ft_catch_error(ret == 2, MALLOC_ERROR, content, head);
	return (0);
}