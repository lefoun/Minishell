/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stone <stone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:15:31 by sdummett          #+#    #+#             */
/*   Updated: 2021/11/22 18:37:37 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**create_args(void)
{
	int		args_nb;
	char	**args;

	args_nb = 5;
	args = malloc(sizeof(char *) * args_nb + 1);
	args[0] = ft_strdup("n_e");
	args[1] = ft_strdup("PWD");
	args[2] = ft_strdup("n");
	args[3] = ft_strdup("OLDPWD");
	args[args_nb - 1] = NULL;
	return (args);
}
