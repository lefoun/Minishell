/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 17:57:35 by nammari           #+#    #+#             */
/*   Updated: 2021/08/02 19:27:56 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	if (!paths)
		return (NULL);
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

char	*get_here_doc_content(int fd, char *limiter, char **str)
{
	char	*tmp;
	char	*tab;

	tmp = NULL;
	tab = NULL;
	*str = ft_strdup("");
	while (get_next_line(fd, &tab, 0) > 0)
	{
		tmp = *str;
		if (!tab)
			break ;
		if (ft_memcmp(tab, limiter, ft_strlen(limiter)) == 0)
		{
			free(tab);
			get_next_line(fd, &tab, 1);
			return (*str);
		}
		*str = ft_strjoin(tmp, tab);
		free(tmp);
		tmp = *str;
		*str = ft_strjoin(tmp, "\n");
		free(tmp);
	}
	double_free(*str, tab);
	return (NULL);
}

int	init_here_doc(char *limiter)
{
	int		here_doc;
	char	*file_content;

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

int	init_command_fds(t_command_vars *commands, char **argv, int argc)
{
	if (ft_strlen(argv[1]) >= 8 && ft_strnstr(argv[1], "here_doc", 8))
	{
		commands->input_fd = init_here_doc(argv[2]);
		if (commands->input_fd < 0)
			return (_error_('b'));
		commands->here_doc = true;
		commands->output_fd = open(argv[argc - 1], O_RDWR | O_APPEND | O_CREAT,
				0666);
		if (commands->output_fd == -1)
			return (_error_('o'));
		commands->name++;
	}
	else
	{
		commands->here_doc = false;
		commands->input_fd = open(argv[1], O_RDONLY | O_NONBLOCK);
		if (commands->input_fd == -1)
			_error_('o');
		commands->output_fd = open(argv[argc - 1], O_RDWR | O_TRUNC | O_CREAT,
				0666);
		if (commands->output_fd == -1)
			_error_('o');
	}
	return (1);
}
