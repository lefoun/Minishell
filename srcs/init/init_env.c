/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:21:14 by sdummett          #+#    #+#             */
/*   Updated: 2021/12/02 17:53:22 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_vars	*init_env(char **envp)
{
	t_vars	*new;

	new = malloc(sizeof(t_vars));
	if (new == NULL)
		return (NULL);
	new->envp = envp;
	new->env = NULL; //DEPRECATED
	new->global = NULL;
	new->prog_name = NULL;
	new->last_exit_status = 0;
	return (new);
}
