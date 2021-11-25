/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_paths.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:52:39 by nammari           #+#    #+#             */
/*   Updated: 2021/11/23 13:53:08 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*search_path(char *string)
{
	if (!string)
		return (NULL);
	if (!(string[0] && string[0] == 'P'))
		return (NULL);
	if (!(string[1] && string[1] == 'A'))
		return (NULL);
	if (!(string[2] && string[2] == 'T'))
		return (NULL);
	if (!(string[3] && string[3] == 'H'))
		return (NULL);
	return (string);
}

char	**get_paths(char *env[])
{
	char			**paths;
	char			*tmp;
	int				i;

	i = 0;
	if (!env)
		return (NULL);
	while (env[i] && search_path(env[i]) == NULL)
		++i;
	if (!env[i])
		return (NULL);
	paths = ft_split(ft_strchr(env[i], '/'), ':');
	i = 0;
	while (paths && paths[i])
	{
		tmp = paths[i];
		paths[i] = ft_strjoin(tmp, "/");
		free(tmp);
		++i;
	}
	return (paths);
}
