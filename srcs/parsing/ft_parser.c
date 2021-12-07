/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:30:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/07 10:37:38 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token_2(t_token *head)
{
	char	*tab[13];
	int		i;

	i = 0;
	tab[0] = "CMD_NAME";
	tab[1] = "CMD_SUFFIX";
	tab[2] = "PIPE";
	tab[3] = "VAR";
	tab[4] = "REDIR_IN";
	tab[5] = "REDIR_HERE_DOC";
	tab[6] = "REDIR_OUT_TRUNC";
	tab[7] = "REDIR_OUT_APPEND";
	tab[8] = "ASSIGN";
	tab[9] = "";
	while (head)
	{
		i = 0;
		if (head->type == CMD_NAME || head->type == ASSIGN)
		{
			while (head->cmd[i])
			{
				printf("This is cmd[%d] %s\n", i, head->cmd[i]);
				++i;
			}
		}
		else
			printf("type : %s | value : %s\n", tab[head->type], head->value);
		head = head->next;
	}
}

void	print_token(t_token *head)
{
	char	*tab[13];

	tab[0] = "CMD_NAME";
	tab[1] = "CMD_SUFFIX";
	tab[2] = "PIPE";
	tab[3] = "VAR";
	tab[4] = "REDIR_IN";
	tab[5] = "REDIR_HERE_DOC";
	tab[6] = "REDIR_OUT_TRUNC";
	tab[7] = "REDIR_OUT_APPEND";
	tab[8] = "ASSIGN";
	tab[9] = "";
	while (head)
	{
		printf("type : %s | value : %s\n", tab[head->type], head->value);
		head = head->next;
	}
}

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

t_token	*map_lst_till_pipe_or_eol(t_token **head)
{
	t_token	*new_head;
	t_token	*new_head_ptr;

	if (*head == NULL)
		return (NULL);
	new_head = dup_elem(*head);
	if (new_head == NULL)
		return (NULL);
	new_head_ptr = new_head;
	(*head) = (*head)->next;
	while (*head != NULL && (*head)->type != PIPE)
	{
		new_head_ptr->next = dup_elem(*head);
		new_head_ptr = new_head_ptr->next;
		(*head) = (*head)->next;
	}
	if (*head && (*head)->type == PIPE)
		*head = (*head)->next;
	return (new_head);
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

//// To be used for testing only 
void	print_args(char **args)
{
	int i;

	i = 0;
	while (args[i])
	{
		printf("args[%d] = %s\n", i, args[i]);
		++i;
	}
}
////

static void	save_last_cmd_word(t_token *lst)
{
	while (lst != NULL)
	{
		if (ft_strcmp(lst->value, "\0") != 0)
		{
			free(variables->last_cmd_word);
			variables->last_cmd_word = ft_strdup(lst->value);
		}
		lst = lst->next;
	}
}

int	ft_parser(char *cmd)
{
	int			nb_cmds;
	char		**args;
	t_token		*head;
	char		**environ;

	head = NULL;
	args = get_processed_cmd_line(cmd);
	ft_tokenize(args, &head);
	save_last_cmd_word(head);
	ft_free_tab(args, 0);
	// print_args(args);
	group_cmd_and_args(&head);
	group_assign(&head);
	// print_token_2(head);
	if (!head)
		return (-1);
	nb_cmds = count_nb_cmds(head);
	environ = get_environment();
	pipex_exec_test(nb_cmds, &head, environ);
	free_environ(environ);
	free_token_lst(head);
	head = NULL;
	return (0);
}
