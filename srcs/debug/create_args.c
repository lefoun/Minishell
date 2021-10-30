/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:15:31 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/30 19:14:03 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char **create_args(void)
{
	//int		i;
	int		args_nb;
	char	**args;

	args_nb = 5;
	args = malloc(sizeof(char *) * args_nb + 1);
	//i = 0;
	args[0] = ft_strdup("-e");
	args[1] = ft_strdup("-ne");
	args[2] = ft_strdup("-n");
	args[3] = ft_strdup("name4=value4");
	args[args_nb - 1] = NULL;
	return (args);
}