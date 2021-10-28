/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:10:51 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/28 17:07:32 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_variable *get_variable(t_variable *vars, char *varname)
{
	int			varname_len;

	varname_len = ft_strlen(varname);
	while (vars != NULL)
	{
		if (ft_strncmp(vars->name, varname, varname_len) == 0)
			return (vars);
		vars = vars->next;
	}
	return (NULL);
}
