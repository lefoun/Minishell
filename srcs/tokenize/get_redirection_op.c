/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirection_op.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:16:52 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/18 11:21:47 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_redir_out_trunc(char **args, int *index, t_token **head)
{
	char	*filename;
	int		ret;

	if (args[*index][0] != '>')
		return (OP_NOT_FOUND);
	++*index;
	if (args[(*index)] == NULL)
		return (ERROR);
	filename = ft_strdup(args[*index]);
	if (ft_catch_error(filename == NULL, filename, head) == MALLOC_ERROR)
		return (1);
	ret = ft_elem_pushback(head, ft_create_elem(filename, REDIR_OUT_TRUNC));
	if (ft_catch_error(ret == 2, filename, head) == MALLOC_ERROR)
		return (1);
	while (args[++*index])
		get_cmd_suffix(args[*index], head);
	return (0);
}

int	get_redir_input_file(char **args, int *index, t_token **head)
{
	char	*filename;
	int		ret;

	if (args[*index][0] != '<' || args[*index][1] == '<')
		return (OP_NOT_FOUND);
	++*index;
	if (args[(*index)] == NULL)
		return (ERROR);
	filename = ft_strdup(args[*index]);
	if (ft_catch_error(filename == NULL, NULL, head) == MALLOC_ERROR)
		return (1);
	ret = ft_elem_pushback(head, ft_create_elem(filename, REDIR_IN));
	if (ft_catch_error(ret == 2, filename, head) == MALLOC_ERROR)
		return (1);
	return (0);
}

int	get_redir_out_append(char **args, int *index, t_token **head)
{
	char	*filename;
	int		ret;

	if (!(args[*index][0] == '>' && args[*index][1] == '>'))
		return (OP_NOT_FOUND);
	++*index;
	if (args[(*index)] == NULL)
		return (ERROR);
	filename = ft_strdup(args[*index]);
	if (ft_catch_error(filename == NULL, NULL, head) == MALLOC_ERROR)
		return (1);
	ret = ft_elem_pushback(head, ft_create_elem(filename, REDIR_OUT_APPEND));
	if (ft_catch_error(ret == 2, filename, head) == MALLOC_ERROR)
		return (1);
	return (0);
}

int	get_redir_input_here_doc(char **args, int *index, t_token **head)
{
	char	*filename;
	int		ret;

	if (!(args[*index][0] == '<' && args[*index][1] == '<'))
		return (OP_NOT_FOUND);
	++*index;
	if (args[(*index)] == NULL)
		return (ERROR);
	filename = ft_strdup(args[*index]);
	if (ft_catch_error(filename == NULL, NULL, head) == MALLOC_ERROR)
		return (1);
	ret = ft_elem_pushback(head, ft_create_elem(filename, REDIR_HERE_DOC));
	if (ft_catch_error(ret == 2, filename, head) == MALLOC_ERROR)
		return (1);
	return (0);
}
