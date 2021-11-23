/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:53:43 by nammari           #+#    #+#             */
/*   Updated: 2021/11/23 18:00:08 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// int	init_command_fds(t_command_vars *commands, char **argv, int argc)
// {
// 	if (ft_strlen(argv[1]) >= 8 && ft_strnstr(argv[1], "here_doc", 8))
// 	{
// 		if (argc < 6)
// 			return (_error_('a'));
// 		commands->input_fd = init_here_doc(argv[2]);
// 		if (commands->input_fd < 0)
// 			return (_error_('b'));
// 		commands->here_doc = true;
// 		commands->output_fd = open(argv[argc - 1], O_RDWR | O_APPEND | O_CREAT,
// 				0666);
// 		if (commands->output_fd == -1)
// 			return (_error_('o'));
// 		commands->name++;
// 	}
// 	else
// 	{
// 		commands->input_fd = open(argv[1], O_RDONLY | O_NONBLOCK);
// 		if (commands->input_fd == -1)
// 			_error_('o');
// 		commands->output_fd = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT,
// 				0666);
// 		if (commands->output_fd == -1)
// 			_error_('o');
// 	}
// 	return (1);
// }

char    *get_input(int output)
{
    char    *tab;
    char    *tmp;
    char    *str;

    tab = NULL;
    tmp = NULL;
    str = ft_strdup("");
    int ret = get_next_line(output, &tab);
    dprintf(2, "Thi sis in ret %d and tab |%s|\n", ret, tab);
    while (get_next_line(output, &tab) > 0)
    {
        tmp = str;
        if (!tab)
            break ;
        str = ft_strjoin(tmp, tab);
        free(tmp);
        tmp = str;
        str = ft_strjoin(tmp, "\n");
        free(tmp);
    }
    free(tab);
    return (str);
}

int write_in_fds(t_fd_chain *head)
{
    t_fd_chain  *tmp;
    int         output;
    char        *output_content;
    
    tmp = head;
    if (head == NULL)
        return (0);
    close(head->fd);
    output = open(head->file_name, O_RDONLY);
    output_content = get_input(output);
    if (output_content == NULL)
        return (-1);
    tmp = tmp->next;
    dprintf(2, "This is output content |%s|\n", output_content);
    while (tmp)
    {
        if (write(tmp->fd, output_content, ft_strlen(output_content)) == -1)
        {
            free(output_content);
            return (_error_('w'));   
        }
        tmp = tmp->next;
    }
    free(output_content);
    return (0);
}

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

int	init_fd_to_commands(t_token *head, t_command_vars *commands)
{
    int         input;
    int         output;
    bool        first_file;

	first_file = true;
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
        else if (input != -2)
            elem_pushback(&(commands->in_head), create_elem(input, head->value));
        else if (output != -2)
            elem_pushback(&(commands->out_head), create_elem(output, head->value));
		if (first_file == true && output != -2)
        {
            first_file = false;
            commands->output_fd = output;
        }
        head = head->next;
	}
    print_fd_chain(commands->out_head);
	return (0);
}

/*

Si il n y a pas de redirection faire comme d'hab.
Sinon ouvrir le premier fichier et écrire dedans (faire en sorte qu'il soit le fd_output)
Ensuite le fermer puis le rouvrir pour écrire dedans.

*/