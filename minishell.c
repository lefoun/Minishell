/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:30:04 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/20 17:48:56 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Add shell features into main function
** by merging git ranches
*/

int	main(void)
{
	// char	*wd;
	// wd = malloc(26);
	// getcwd(wd, 26);
	// printf("cwd : |%s|\n", wd);
	pwd();
	printf("pepesh €\n");
	echo("hello world!", true);
	return (0);
}
