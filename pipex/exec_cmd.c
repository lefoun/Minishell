/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 02:12:37 by stone             #+#    #+#             */
/*   Updated: 2021/08/14 16:23:24 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	check_path(char *path, t_path *path_type)
{
	int	i;

	path_type->is_absolute = false;
	path_type->is_relative = false;
	path_type->is_dot_slash = false;
	if (path[0] == '/')
		path_type->is_absolute = true;
	else if (path[0] == '.' && path[1] == '/')
	{
		path_type->is_relative = true;
		path_type->is_dot_slash = true;
	}
	else
	{
		i = 0;
		while (path[i] != '\0')
		{
			if (path[i] == '/')
			{
				path_type->is_relative = true;
				return ;
			}
			i++;
		}
	}
}

void	exec_cmd(char **args, char **path)
{
	t_path	path_type;
	int		i;

	 check_path(args[0], &path_type);
	if (path_type.is_relative || path_type.is_absolute)
	{
		if (path_type.is_dot_slash)
			execve(args[0] + 2, args, NULL);
		else
			execve(args[0], args, NULL);
	}
	else
	{
		i = 0;
		while (path[i] != NULL)
		{
			execve(path[i], args, NULL);
			i++;
		}
	}
	perror(args[0]);
}
