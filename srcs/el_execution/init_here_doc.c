/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_here_doc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:54:35 by nammari           #+#    #+#             */
/*   Updated: 2021/12/08 21:33:15 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*free_gnl(char **tab, char **str, int fd)
{
	free(*tab);
	gnl_here_doc(fd, tab, 1);
	return (*str);
}

char	*get_here_doc_content(int fd, char *limiter, char **str)
{
	char	*tmp;
	char	*tab;

	tmp = NULL;
	tab = NULL;
	*str = ft_strdup("");
	while (gnl_here_doc(fd, &tab, 0) > 0)
	{
		tmp = *str;
		if (!tab)
			break ;
		if (ft_strcmp(tab, limiter) == 0)
			return (free_gnl(&tab, str, fd));
		*str = ft_strjoin(tmp, tab);
		free(tmp);
		tmp = *str;
		*str = ft_strjoin(tmp, "\n");
		free(tmp);
	}
	double_free(*str, tab);
	return (NULL);
}

int	init_here_doc(char *limiter, t_command_vars *com)
{
	int		here_doc;
	char	*file_content;

	com->is_here_doc = true;
	file_content = NULL;
	file_content = get_here_doc_content(0, limiter, &file_content);
	if (!file_content)
		return (-1);
	here_doc = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0666);
	if (here_doc == -1)
	{
		free(file_content);
		return (_error_('o'));
	}
	if (write(here_doc, file_content, ft_strlen(file_content)) == -1)
	{
		free(file_content);
		return (_error_('w'));
	}
	close(here_doc);
	here_doc = open("here_doc", O_RDWR);
	free(file_content);
	return (here_doc);
}
