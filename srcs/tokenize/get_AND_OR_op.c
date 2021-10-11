/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_AND_OR_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 16:45:11 by nammari           #+#    #+#             */
/*   Updated: 2021/10/11 18:06:40 by sdummett         ###   ########.fr       */
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
	if (ft_catch_error(ret == 2, content, head) == MALLOC_ERROR)
		return (1);
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
	ft_catch_error(ret == 2, content, head);
	return (0);
}