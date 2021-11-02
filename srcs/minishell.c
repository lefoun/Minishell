/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/11/02 17:51:33 by nammari          ###   ########.fr       */
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

	while (true)
	{
		cmd = readline("# pepe_shell $>");
		ft_parser(cmd);
		free(cmd);
	}
	// printf("This is the return value of get %d and Type %d and Content %s\n", return_value, head->type, head->value);
	return (0);
}
