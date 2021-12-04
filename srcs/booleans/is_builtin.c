/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_main_process_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 16:27:23 by nammari           #+#    #+#             */
/*   Updated: 2021/12/04 17:14:41 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

bool	is_main_process_builtin(t_command_vars *commands)
{	
	if (ft_strcmp(commands->name[0], "cd") == 0)
		return (true);
	else if (ft_strcmp(commands->name[0], "pwd") == 0)
		return (true);
	else if (ft_strcmp(commands->name[0], "env") == 0)
		return (true);
	else if (ft_strcmp(commands->name[0], "exit") == 0)
		return (true);
	else if (ft_strcmp(commands->name[0], "export") == 0)
		return (true);
	else if (ft_strcmp(commands->name[0], "unset") == 0)
		return (true);
	else if (commands->is_assign == true)
		return (true);
	return (false);
}