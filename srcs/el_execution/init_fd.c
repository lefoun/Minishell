/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noufel <noufel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:53:43 by nammari           #+#    #+#             */
/*   Updated: 2021/11/24 18:00:24 by noufel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// char    *get_input(int output)
// {
//     char    *tab;
//     char    *tmp;
//     char    *str;

//     tab = NULL;
//     tmp = NULL;
//     str = ft_strdup("");
//     while (get_next_line(output, &tab) > 0)
//     {
//         tmp = str;
//         if (!tab)
//             break ;
//         str = ft_strjoin(tmp, tab);
//         free(tmp);
//         tmp = str;
//         str = ft_strjoin(tmp, "\n");
//         free(tmp);
//     }
//     free(tab);
//     return (str);
// }

// int write_in_fds(t_fd_chain *head)
// {
//     t_fd_chain  *tmp;
//     //int         output;
//     char        *output_content;
    
//     tmp = head;
//     if (head == NULL)
//         return (0);
//     output_content = get_input(2);
//     if (output_content == NULL)
//         return (-1);
//     tmp = tmp->next;
//     while (tmp)
//     {
//         if (write(tmp->fd, output_content, ft_strlen(output_content)) == -1)
//         {
//             free(output_content);
//             return (_error_('w'));   
//         }
//         tmp = tmp->next;
//     }
//     free(output_content);
//     return (0);
// }

// The above functions will be deleted. Keeping them here just to be sure everything
// Works fine before deleting them.
// ---------------- 

void    print_fd_chain(t_fd_chain *head)
{
    int i = 1;
    
    while (head)
    {
        dprintf(2, "This is Elem n# %d -> Named |%s| and fd : %d\n", i, head->file_name, head->fd);
        ++i;
        head = head->next;
    }
}

int fd_chain_len(t_fd_chain *head)
{
    int i;

    i = 0;
    while (head != NULL)
    {
        head = head->next;
        ++i;
    }
    return (i);
}

void    push_elem_and_update_com_fd(t_command_vars *com, t_token *head, int in, int out)
{
    if (in > -1)
    {
        elem_pushback(&(com->in_head), create_elem(in, head->value));
        com->input_fd = in;
    }
    else if (out > -1)
    {
        elem_pushback(&(com->out_head), create_elem(out, head->value));
        com->output_fd = out;
    }
}

int	init_fd_to_commands(t_token *head, t_command_vars *com)
{
    int input;
    int output;
    while (head && head->type != PIPE)
	{
        input = -2;
        output = -2;
		if (head->type == REDIR_IN)
			input = open(head->value, O_RDONLY);
		else if (head->type == REDIR_HERE_DOC)
			input = init_here_doc(head->value);
		else if (head->type == REDIR_OUT_APPEND)
			output = open(head->value, O_RDWR | O_APPEND | O_CREAT, 0666);
		else if (head->type == REDIR_OUT_TRUNC)
			output = open(head->value, O_RDWR | O_TRUNC | O_CREAT, 0666);
		if (input == -1 || output == -1)
			return (_error_('o'));
        push_elem_and_update_com_fd(com, head, input, output);
        head = head->next;
	}
    if (com->out_head != NULL && fd_chain_len(com->out_head) > 1)
        close_unused_fd_chain(com->out_head);
    if (com->in_head != NULL && fd_chain_len(com->in_head) > 1)
       close_unused_fd_chain(com->in_head);
	return (0);
}
