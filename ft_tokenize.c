/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tokenize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 18:33:37 by sdummett          #+#    #+#             */
/*   Updated: 2021/09/30 21:09:15 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token *ft_tokenize(char *cmd)
{
	t_token	*head;
	char	**splited_arguments;
	int		i;
	int		j;
	(void)head;
	(void)splited_arguments;
	return (NULL);

	i = 0;
	while (cmd[i])
	{
	// Add args to get_next_type_operator call
	// i = get_next_type_operator();
		// Ad function
		//get_op_elem();
		j = 0;
		while (!is_space(*cmd))
			++j;
	}
	return (NULL);
}
