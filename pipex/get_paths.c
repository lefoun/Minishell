/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stone <stone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 12:57:12 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/12 17:06:08 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_paths(char **paths)
{
	int	i;

	i = 0;
	while (paths[i] != NULL)
	{
		free(paths[i]);
		i++;
	}
	free(paths);
}

void	cat_cmd_with_path(char **path, char *cmd)
{
	char	*tmp;
	char	*new;
	int		i;

	i = 0;
	while (path[i] != NULL)
	{
		tmp = ft_strjoin(path[i], "/");
		new = ft_strjoin(tmp, cmd);
		free(path[i]);
		free(tmp);
		path[i] = new;
		i++;
	}
}

char	**get_paths(char *cmd)
{
	extern char	**__environ;
	char		**path;
	char		*tmp;
	int			i;

	i = 0;
	tmp = NULL;
	while (__environ[i] != NULL)
	{
		tmp = ft_strnstr(__environ[i], "PATH=", 5);
		if (tmp != NULL)
			break ;
		i++;
	}
	path = ft_split(tmp, ':');
	rm_n_first_char(&path[0], 5);
	cat_cmd_with_path(path, cmd);
	return (path);
}
