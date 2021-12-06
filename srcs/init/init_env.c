/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:21:14 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/06 14:35:51 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_vars	*init_env(char **av)
{
	t_vars	*new;

	new = malloc(sizeof(t_vars));
	if (new == NULL)
		return (NULL);
	new->env = NULL;
	new->global = NULL;
	new->last_cmd_word = NULL;
	new->prog_name = av[0] + 2;
	new->last_exit_status = 0;
	return (new);
}
