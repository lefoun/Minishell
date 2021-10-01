/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/01 13:51:38 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	get_redirection_simple(char *str, int index, t_token **head)
{
	t_token	*elem;
	int		i;
	int		j;

	if (!is_redirection_input(str) && !is_redirection_output_trunc(str))
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
	ft_pushback(head, elem);
	return (true);
}

bool	get_redirection_double(char *str, int index, t_token **head)
{
	t_token	*elem;
	int		i;
	int		j;

	if (!is_redirection_input_here_doc(str) \
			&& !is_redirection_output_append(str))
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
		elem->type = REDIR_HERE_DOC;
	else
		elem->type = REDIR_OUT_APPEND;
	elem->value = ft_strdup_index(str + i, j);
	if (!elem->value)
		return (false);
	ft_pushback(head, elem);
	return (true);
}

int     get_index_of_operator(char *arg)
{
	int	i;

	i = 0;
	return (i);
}


/*
** Create boolean function for function pointer
** bool	get_
*/

/*
** Add linked list related functions

t_token	*ft_create_element(t_token **head, char *arg, int index)
{

}

*/

int	main(void)
{
	char *cmd;
	// Add readline here
	cmd = readline("# pepe_shell $>");
	printf("command received: |%s|\n", cmd);
	ft_parser(cmd);
	free(cmd);
	return (0);
}

/*
** [ DEPRECATED ]
**

bool	is_operator(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == '&')
		return (true);
	return (false);
	// if (*str == '&' && *(str + 1) != '&')
	// 	return (false);
	// else
	// 	return (true);
}

*/
