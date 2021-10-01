/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/01 16:26:15 by sdummett         ###   ########.fr       */
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
	// Add readline here
	cmd = readline("# pepe_shell $>");
	printf("command received: |%s|\n", cmd);
	ft_parser(cmd);
	free(cmd);
	return (0);
}
