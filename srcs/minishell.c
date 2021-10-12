/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/12 15:37:02 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Add shell features into main function
** by merging git ranches
*/


int	main(void)
{
	char *cmd;
	t_token	*head;

	head = NULL;
	while (true)
	{
		cmd = readline("# pepe_shell $>");
		printf("Number of words = %d\n", count_word_nb(cmd));
		//printf("command received: |%s|\n", cmd);
		//ft_parser(cmd);
		// return_value = get_redir_out_trunc(cmd, 0, &head);
		// ft_tokenize(cmd, &head);
		// free_token_lst(head);
		free(cmd);
	}
	// printf("This is the return value of get %d and Type %d and Content %s\n", return_value, head->type, head->value);
	return (0);
}
