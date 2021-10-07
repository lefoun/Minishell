/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirection_op.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:16:52 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/06 18:07:30 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_redir_out_trunc(char *str, t_token **head)
{
	char	*file_name;
	int		ret;
	int		i;
	int		j;

	if (*str != '>')
		return (1);
	i = 0;
	j = 0;
	while (is_operator(str[i]))
		++i;
	while (is_whitespace(str[i]))
		++i;
	while (str[i + j] && !is_whitespace(str[i + j]) && !is_operator(str[i + j]))
		++j;
	file_name = ft_strdup_index(str + i, j);
	ret = ft_elem_pushback(head, ft_create_elem(file_name, REDIR_OUT_TRUNC));
	if (ret == 2)
	{
		free(file_name);	
		return (2);
	}
	return (0);
}

int	get_redir_input_file(char *str, t_token **head)
{
	char	*file_name;
	int		ret;
	int		i;
	int		j;

	if (*str != '<' || str[1] == '<')
		return (1);
	i = 0;
	j = 0;
	while (is_operator(str[i]))
		++i;
	while (is_whitespace(str[i]))
		++i;
	while (str[i + j] && !is_whitespace(str[i + j]) && !is_operator(str[i + j]))
		++j;
	file_name = ft_strdup_index(str + i, j);
	ret = ft_elem_pushback(head, ft_create_elem(file_name, REDIR_IN));
	if (ret == 2)
	{
		free(file_name);	
		return (2);
	}
	return (0);
}

int	get_redir_out_append(char *str, t_token **head)
{
	char	*file_name;
	int		ret;
	int		i;
	int		j;

	if (!(*str == '>' && str[1] == '>'))
		return (1);
	i = 0;
	j = 0;
	while (is_operator(str[i]))
		++i;
	while (is_whitespace(str[i]))
		++i;
	while (str[i + j] && !is_whitespace(str[i + j]) && !is_operator(str[i + j]))
		++j;
	file_name = ft_strdup_index(str + i, j);
	ret = ft_elem_pushback(head, ft_create_elem(file_name, REDIR_OUT_APPEND));
	if (ret == 2)
	{
		free(file_name);	
		return (2);
	}
	return (0);
}

int	get_redir_input_here_doc(char *str, t_token **head)
{
	char	*file_name;
	int		ret;
	int		i;
	int		j;

	(void)index;
	if (!(*str == '<' && str[1] == '<'))
		return (1);
	i = 0;
	j = 0;
	while (is_operator(str[i]))
		++i;
	while (is_whitespace(str[i]))
		++i;
	while (str[i + j] && !is_whitespace(str[i + j]) && !is_operator(str[i + j]))
		++j;
	file_name = ft_strdup_index(str + i, j);
	ret = ft_elem_pushback(head, ft_create_elem(file_name, REDIR_HERE_DOC));
	if (ret == 2)
	{
		free(file_name);	
		return (2);
	}
	return (0);
}
