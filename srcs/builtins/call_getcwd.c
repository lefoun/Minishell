/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   call_getcwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 16:36:13 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/28 16:57:19 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*call_getcwd()
{
	unsigned int	i;
	unsigned int	len;
	char			*path;

	i = 1;
	path = NULL;
	while (true)
	{
		len = 42 * i;
		path = malloc(sizeof(char) * len);
		if (getcwd(path, len) != NULL)
			return (path);
		free(path);
		i++;
		if (len > MAX_PATH_LEN)
			break ;
	}
	return (NULL);
}