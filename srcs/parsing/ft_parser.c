/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noufel <noufel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:30:44 by sdummett          #+#    #+#             */
/*   Updated: 2021/11/05 16:00:09 by noufel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_token_2(t_token *head)
{
	char *tab[13];
	int	i;

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
		if (head->type == CMD_NAME)
		{
			while (head->cmd[i])
			{
				printf("This is cmd[%d] %s\n", i, head->cmd[i]);
				++i;
			}
			printf("This is cmd[%d] %s\n", i, head->cmd[i]);

		}
		else
			printf("type : %s | value : %s\n", tab[head->type], head->value);
		head = head->next;
	}
}

void	print_token(t_token *head)
{
	char *tab[13];

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

t_token	*dup_elem(t_token *src_elem)
{
	t_token	*dst_elem;
	
	if (src_elem == NULL)
		return (NULL);
	dst_elem = malloc(sizeof(*dst_elem));
	if (dst_elem == NULL)
		return (NULL);
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
	new_head_ptr = new_head;
	(*head) = (*head)->next;
	while (*head && (*head)->type != PIPE)
	{
		new_head->next = dup_elem(*head);
		new_head = new_head->next;
		(*head) = (*head)->next;
	}
	if (*head && (*head)->type == PIPE)
		*head = (*head)->next;
	return (new_head_ptr);
}

int	ft_parser(char *cmd)
{
	char	**args;
	t_token *head;
	t_token	*tmp;

	head = NULL;
	args = get_prosseced_cmd_line(cmd);
	ft_tokenize(args, &head);
	if (!head)
		return (-1);
	tmp = map_lst_till_pipe_or_eol(&head);
	print_token(tmp);
	return (0);
}
