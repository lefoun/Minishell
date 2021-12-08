/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:30:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/08 22:13:48 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**copy_cmd_elem(char **src)
{
	int		i;
	char	**dst;

	i = 0;
	if (!src || !*src)
		return (NULL);
	while (src[i])
		++i;
	dst = malloc(sizeof(*dst) * (i + 1));
	if (dst == NULL)
		return (NULL);
	i = -1;
	while (src[++i])
		dst[i] = ft_strdup(src[i]);
	dst[i] = NULL;
	return (dst);
}

t_token	*dup_elem(t_token *src_elem)
{
	t_token	*dst_elem;

	if (src_elem == NULL)
		return (NULL);
	dst_elem = malloc(sizeof(*dst_elem));
	if (dst_elem == NULL)
		return (NULL);
	dst_elem->cmd = copy_cmd_elem(src_elem->cmd);
	dst_elem->value = ft_strdup(src_elem->value);
	dst_elem->type = src_elem->type;
	dst_elem->next = NULL;
	return (dst_elem);
}

int	count_nb_cmds(t_token *head)
{
	int	nb_cmd;

	nb_cmd = 0;
	while (head)
	{
		if (head->type == CMD_NAME || head->type == ASSIGN)
			nb_cmd++;
		head = head->next;
	}
	return (nb_cmd);
}

static void	save_last_cmd_word(t_token *lst)
{
	while (lst != NULL)
	{
		if (ft_strcmp(lst->value, "\0") != 0)
		{
			free(g_variables->last_cmd_word);
			g_variables->last_cmd_word = ft_strdup(lst->value);
		}
		lst = lst->next;
	}
}

int	ft_parser(char *cmd)
{
	char		**args;
	char		**environ;
	int			nb_cmds;
	t_token		*head;

	head = NULL;
	args = get_processed_cmd_line(cmd);
	ft_tokenize(args, &head);
	save_last_cmd_word(head);
	ft_free_tab(args, 0);
	group_cmd_and_args(&head);
	group_assign(&head);
	if (!head)
		return (-1);
	nb_cmds = count_nb_cmds(head);
	environ = get_environment();
	pipex_exec_test(nb_cmds, &head, environ);
	free_environ(environ);
	head = NULL;
	return (0);
}
