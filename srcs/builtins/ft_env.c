/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 16:41:43 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/02 21:50:05 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_env(char **args)
{
	unsigned int	i;

	(void)args;
	i = 0;
	while (variables->envp[i] != NULL)
	{
		printf("%s\n", variables->envp[i]);
		i++;
	}
	return (0);
}
