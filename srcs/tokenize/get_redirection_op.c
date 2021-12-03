/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_redirection_op.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:16:52 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/03 21:32:26 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_redir_out_trunc(char **args, int *index, t_token **head)
{
	char	*filename;
	int		ret;
	int		i;

	if (!(args[*index][0] == '>' && args[*index][1] == '\0'))
		return (OP_NOT_FOUND);
	++*index;
	if (args[(*index)] == NULL)
		return (3);
	filename = ft_strdup(args[*index]);
	if (ft_catch_error(filename == NULL, filename, head) == MALLOC_ERROR)
		return (2);
	ret = ft_elem_pushback(head, ft_create_elem(filename, REDIR_OUT_TRUNC));
	if (ft_catch_error(ret == 2, filename, head) == MALLOC_ERROR)
		return (2);
	i = *index;
	while (args[++i] && !is_operator(args[i][0]))
	{
		get_cmd_suffix(args[++*index], head);
	}
	return (0);
}

int	get_redir_input_file(char **args, int *index, t_token **head)
{
	char	*filename;
	int		ret;
	int		i;

	if (!(args[*index][0] == '<' && args[*index][1] == '\0'))
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
	i = *index;
	while (args[++i] && !is_operator(args[i][0]))
	{
		++*index;
		get_cmd(args, index, head);
	}
	return (0);
}

int	get_redir_out_append(char **args, int *index, t_token **head)
{
	char	*filename;
	int		ret;
	int		i;

	if (!(args[*index][0] == '>' && args[*index][1] == '>'))
		return (OP_NOT_FOUND);
	++*index;
	if (args[*index] == NULL)
		return (ERROR);
	filename = ft_strdup(args[*index]);
	if (ft_catch_error(filename == NULL, NULL, head) == MALLOC_ERROR)
		return (1);
	ret = ft_elem_pushback(head, ft_create_elem(filename, REDIR_OUT_APPEND));
	if (ft_catch_error(ret == 2, filename, head) == MALLOC_ERROR)
		return (1);
	i = *index;
	while (args[++i] && !is_operator(args[i][0]))
	{
		get_cmd_suffix(args[++*index], head);
	}
	return (0);
}

int	get_redir_input_here_doc(char **args, int *index, t_token **head)
{
	char	*filename;
	int		ret;
	int		i;

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
	i = *index;
	while (args[++i] && !is_operator(args[i][0]))
	{
		get_cmd_suffix(args[++*index], head);
	}
	return (0);
}

int	get_redirection_op(int (*get_redirection[])(char **, int *, t_token **),
							char **args, int *index, t_token **head)
{
	int	j;
	int	ret;

	j = -1;
	if (args[*index + 1] && is_operator(args[*index + 1][0]))
	{
		ft_putstr_fd("pepe_shell: syntax error near unexpected token `", 2);
		ft_putstr_fd(args[*index + 1], 2);
		ft_putstr_fd("\'\n", 2);
		return (3);
	}
	else if (args[*index + 1] == NULL)
	{
		ft_putstr_fd("pepe_shell: syntax error near unexpected"
			" token `newline'\n", 2);
		return (3);
	}
	while (++j < 4)
	{
		ret = (*get_redirection[j])(args, index, head);
		if (ret == 0)
			return (0);
	}
	return (1);
}
