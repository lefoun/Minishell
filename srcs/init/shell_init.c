/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stone <stone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 20:21:03 by stone             #+#    #+#             */
/*   Updated: 2021/11/30 19:31:54 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	shell_init(char **av)
{
	variables->prog_name = ft_strdup(av[0] + 2);
	// char *env = getenv("TERM");
	// int slot = ttyslot();
	// printf("env => %s\n", env);
	// printf("slot => %d\n", slot);
	return (0);
}