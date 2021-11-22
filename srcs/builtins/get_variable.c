/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stone <stone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:10:51 by sdummett          #+#    #+#             */
/*   Updated: 2021/11/22 18:11:29 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//
// Maybe use the global instead of t_variable *vars
//

t_variable	*get_variable(t_variable *vars, char *varname)
{
	int			varname_len;

	while (vars != NULL)
	{
		varname_len = get_greatest_len(vars->name, varname);
		if (ft_strncmp(vars->name, varname, varname_len) == 0)
			return (vars);
		vars = vars->next;
	}
	return (NULL);
}
