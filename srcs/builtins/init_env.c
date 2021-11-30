/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stone <stone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 17:21:14 by sdummett          #+#    #+#             */
/*   Updated: 2021/11/30 19:30:12 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_vars	*init_env(void)
{
	t_vars	*new;

	new = malloc(sizeof(t_vars));
	if (new == NULL)
		return (NULL);
	new->env = NULL;
	new->global = NULL;
	new->prog_name = NULL;
	new->last_exit_status = 0;
	return (new);
}
