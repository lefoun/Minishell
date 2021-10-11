/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirection_op.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:16:52 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/11 18:25:08 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_redir_out_trunc(char *str, t_token **head)
{
	char	*filename;
	int		ret;
	int		i;
	int		j;

	if (*str != '>')
		return (OP_NOT_FOUND);
	i = 0;
	j = 0;
	while (is_operator(str[i]))
		++i;
	while (is_whitespace(str[i]))
		++i;
	while (str[i + j] && !is_whitespace(str[i + j]) && !is_operator(str[i + j]))
		++j;
	filename = ft_strdup_index(str + i, j);
	if (ft_catch_error(filename == NULL, filename, head) == MALLOC_ERROR)
		return (1);
	ret = ft_elem_pushback(head, ft_create_elem(filename, REDIR_OUT_TRUNC));
	if (ft_catch_error(ret == 2, filename, head) == MALLOC_ERROR)
		return (1);
	return (0);
}

int	get_redir_input_file(char *str, t_token **head)
{
	char	*filename;
	int		ret;
	int		i;
	int		j;

	if (*str != '<' || str[1] == '<')
		return (OP_NOT_FOUND);
	i = 0;
	j = 0;
	while (is_operator(str[i]))
		++i;
	while (is_whitespace(str[i]))
		++i;
	while (str[i + j] && !is_whitespace(str[i + j]) && !is_operator(str[i + j]))
		++j;
	filename = ft_strdup_index(str + i, j);
	if (ft_catch_error(filename == NULL, NULL, head) == MALLOC_ERROR)
		return (1);
	ret = ft_elem_pushback(head, ft_create_elem(filename, REDIR_IN));
	if (ft_catch_error(ret == 2, filename, head) == MALLOC_ERROR)
		return (1);
	return (0);
}

int	get_redir_out_append(char *str, t_token **head)
{
	char	*filename;
	int		ret;
	int		i;
	int		j;

	if (!(*str == '>' && str[1] == '>'))
		return (OP_NOT_FOUND);
	i = 0;
	j = 0;
	while (is_operator(str[i]))
		++i;
	while (is_whitespace(str[i]))
		++i;
	while (str[i + j] && !is_whitespace(str[i + j]) && !is_operator(str[i + j]))
		++j;
	filename = ft_strdup_index(str + i, j);
	if (ft_catch_error(filename == NULL, NULL, head) == MALLOC_ERROR)
		return (1);
	ret = ft_elem_pushback(head, ft_create_elem(filename, REDIR_OUT_APPEND));
	if (ft_catch_error(ret == 2, filename, head) == MALLOC_ERROR)
		return (1);
	return (0);
}

int	get_redir_input_here_doc(char *str, t_token **head)
{
	char	*filename;
	int		ret;
	int		i;
	int		j;

	if (!(*str == '<' && str[1] == '<'))
		return (OP_NOT_FOUND);
	i = 0;
	j = 0;
	while (is_operator(str[i]))
		++i;
	while (is_whitespace(str[i]))
		++i;
	while (str[i + j] && !is_whitespace(str[i + j]) && !is_operator(str[i + j]))
		++j;
	filename = ft_strdup_index(str + i, j);
	if (ft_catch_error(filename == NULL, NULL, head) == MALLOC_ERROR)
		return (1);
	ret = ft_elem_pushback(head, ft_create_elem(filename, REDIR_HERE_DOC));
	if (ft_catch_error(ret == 2, filename, head) == MALLOC_ERROR)
		return (1);
	return (0);
}
