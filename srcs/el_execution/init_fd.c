/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:53:43 by nammari           #+#    #+#             */
/*   Updated: 2021/12/06 14:54:13 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "execution.h"

void	print_fd_chain(t_fd_chain *head)
{
	int	i;

	i = 1;
	while (head)
	{
		dprintf(2, "This is Elem n# %d -> Named |%s| and fd : %d\n",
			i, head->file_name, head->fd);
		++i;
		head = head->next;
	}
}

int	fd_chain_len(t_fd_chain *head)
{
	int	i;

	i = 0;
	while (head != NULL)
	{
		head = head->next;
		++i;
	}
	return (i);
}

void	push_elem_and_update_com_fd(t_command_vars *com, t_token *head,
									int *in, int *out)
{
	if (head->type == REDIR_IN)
		*in = open(head->value, O_RDONLY);
	else if (head->type == REDIR_HERE_DOC)
		*in = init_here_doc(head->value, com);
	else if (head->type == REDIR_OUT_APPEND)
		*out = open(head->value, O_RDWR | O_APPEND | O_CREAT, 0666);
	else if (head->type == REDIR_OUT_TRUNC)
		*out = open(head->value, O_RDWR | O_TRUNC | O_CREAT, 0666);
	if (*in > -1)
	{
		elem_pushback(&com->in_head, create_elem(*in, head->value));
		com->input_fd = *in;
	}
	else if (*out > -1)
	{
		elem_pushback(&com->out_head, create_elem(*out, head->value));
		com->output_fd = *out;
	}
}

int	init_fd_to_commands(t_token *head, t_command_vars *com)
{
	int		input;
	int		output;
	t_token	*tmp;

	tmp = head;
	while (tmp != NULL && tmp->type != PIPE)
	{
		input = -2;
		output = -2;
		push_elem_and_update_com_fd(com, tmp, &input, &output);
		if (input == -1 || output == -1)
			return (_error_('o'));
		tmp = tmp->next;
	}
	if (com->out_head != NULL && fd_chain_len(com->out_head) > 1)
		close_unused_fd_chain(&com->out_head);
	if (com->in_head != NULL && fd_chain_len(com->in_head) > 1)
		close_unused_fd_chain(&com->in_head);
	return (0);
}
