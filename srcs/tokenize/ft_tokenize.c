/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:33:37 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/19 14:36:28 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



void	init_function_pointer(int (*get_redirection[])(char **, int *, t_token **))
{
	get_redirection[0] = get_redir_out_append;
	get_redirection[1] = get_redir_out_trunc;
	get_redirection[2] = get_redir_input_here_doc;
	get_redirection[3] = get_redir_input_file;
}

int	get_redirection_op(int (*get_redirection[])(char **, int *, t_token **),
							char **args, int *index, t_token **head)
{
	int	j;
	int	ret;

	j = 0;
	if (args[*index + 1] && is_operator(args[*index + 1][0]))
	{
		printf("pepe_shell: syntax error near unexpected token `%s\'\n", args[*index + 1]);
		return (3);
	}
	else if (args[*index + 1] == NULL)
	{
		printf("pepe_shell: syntax error near unexpected token `newline'\n");
		return (3);
	}
	while (j < 4)
	{
		ret = (*get_redirection[j])(args, index, head);
		if (ret == 0)
			return (0);
		++j;
	}
	return (1);
}

void	ft_new_tokenize(char **args, t_token **head)
{
	int	i;

	i = 0;
	int	(*get_redirection[4])(char **arg, int *index, t_token **head);
	init_function_pointer(get_redirection);
	while (args && args[i])
	{
		if (is_redirection(args[i][0]))
		{
			if (get_redirection_op(get_redirection, args, &i, head) > 0)
				return ;
		}
		else if (args[i][0] == '|')
			get_pipe_op(args[i], head);
		else if (is_next_word_assignment(args[i]))
			get_assignment(args[i], head);
		else
			get_cmd(args, &i, head);
		if (args[i])
			++i;
	}
}


// t_token *ft_tokenize(char *cmd, t_token **head)
// {
// 	int		i;
// 	int		j;
// 	int		ret;
// 	bool	redirection;
// 	char	prefix_op;

// 	i = 0;
// 	*head = NULL;
// 	redirection = false;
// 	prefix_op = '0';
// 	int	(*get_redirection[7])(char *arg, t_token **head);
// 	init_function_pointer(get_redirection);
// 	while (cmd[i])
// 	{
// 		while (is_whitespace(cmd[i]))
// 			i++;
// 		if (is_next_word_assignment(cmd + i))
// 		{
// 			ret = get_assignment(cmd + i, head);
// 			ft_catch_error(ret == 2, NULL, head);
// 			while (cmd[i] != '\0' && !is_operator(cmd[i]) && !is_whitespace(cmd[i]))
// 				i++;
// 		}
// 		else
// 		{
// 			ret = get_cmd(cmd + i, head);
// 			if (ft_catch_error(ret == 2, NULL, head) == MALLOC_ERROR)
// 				return (NULL);
// 			while (cmd[i] != '\0' && !is_operator(cmd[i]))
// 				i++;
// 		}
// 		if (cmd[i] == '<' || cmd[i] == '>')
// 			redirection = true;
		
// 		if (is_operator(cmd[i]))
// 		{
// 			prefix_op = cmd[i];
// 			j = 0;
// 			while ((*get_redirection[j])(cmd + i , head) != 0 && j < 7)
// 				++j;
// 		}
// 		//add a function that checks if we have false operators like >>>
// 		while (is_operator(cmd[i]))
// 			++i;
// 		while (is_whitespace(cmd[i]))
// 			++i;
// 		if (redirection == true)
// 			while (cmd[i] != '\0' && !is_operator(cmd[i]) && !is_whitespace(cmd[i]))
// 				++i;
// 		redirection = false;
// 	}
// 	print_token(*head);
// 	return (*head);
// }
