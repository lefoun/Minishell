/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_redirection_op.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:16:52 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/30 21:00:47 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	get_redirection_op(char *str, int index, t_token **head)
{
	t_token	*elem;
	int		i;
	int		j;
	(void)head;
	(void)index;

	if (*str != '>' && *str != '<')
		return (false);
	i = 0;
	j = 0;
	while (is_whitespace(str[i]))
		++i;
	while (str[i + j] && !is_whitespace(str[i + j]))
		++j;
	elem = malloc(sizeof(elem));
	if (!elem)
		return (false);
	if (*str == '<')
		elem->type = REDIR_IN;
	else
		elem->type = REDIR_OUT_TRUNC;
	elem->value = ft_strdup_index(str + i, j);
	if (!elem->value)
		return (false);
	// Add function
	//ft_pushback(head, elem);
	return (true);
}
