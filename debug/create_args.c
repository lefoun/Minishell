/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 18:15:31 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/22 18:21:30 by sdummett         ###   ########.fr       */
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
	args[0] = ft_strdup("name=value");
	args[1] = ft_strdup("name1=value1");
	args[2] = ft_strdup("name3=");
	args[3] = ft_strdup("name4=value4");
	args[args_nb] = NULL;
	return (args);
}