/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_get_next_line_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noufel <noufel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:03:26 by nammari           #+#    #+#             */
/*   Updated: 2021/11/25 10:19:55 by noufel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	lst_free(t_struct **struct_pointer, int fd)
{
	t_struct	*previous;
	t_struct	*current;

	previous = NULL;
	current = *struct_pointer;
	while (current)
	{
		if (current->fd == fd)
		{
			if (previous == NULL)
				*struct_pointer = current->next;
			else
				previous->next = current->next;
			ft_memset_gnl(current->buffer, 0, BUFFER_SIZE + 1);
			free(current);
			break ;
		}
		previous = current;
		current = current->next;
	}
}

int	check_eol(char *buffer, int	reason)
{
	int	i;

	i = 0;
	if (!buffer)
		return (FALSE);
	if (reason == 'b')
	{
		while (i < BUFFER_SIZE)
		{
			if (buffer[i] == '\n')
				return (i);
			++i;
		}
	}
	else
	{
		while (buffer[i])
		{
			if (buffer[i] == '\n')
				return (i);
			++i;
		}
	}
	return (FALSE);
}

int	return_function(char **string, char buffer[], char **line, int ret_reason)
{
	int	i;

	if (ret_reason == ERROR)
	{
		free(*string);
		return (ERROR);
	}
	i = check_eol(string[0], 'a');
	if (i > -1)
		string[0][i] = '\0';
	i = check_eol(buffer, 'b');
	ft_memset_gnl(buffer, 0, i + 1);
	if (ret_reason != END_FILE)
		free(*line);
	*line = ft_strdup_gnl(string[0]);
	free(*string);
	return (ret_reason);
}

int	read_func(int fd, char buffer[], char **line)
{
	int		bytes_read;
	char	*string;
	char	*tmp;
	int		i;

	tmp = NULL;
	i = 0;
	while (buffer[i] == '\0' && i < BUFFER_SIZE)
		++i;
	string = ft_strdup_gnl(buffer + i);
	while (check_eol(buffer, 'b') == FALSE)
	{
		ft_memset_gnl(buffer, 0, BUFFER_SIZE);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (return_function(&string, buffer, line, ERROR));
		if (bytes_read == 0)
			return (return_function(&string, buffer, line, END_FILE));
		tmp = ft_strdup_gnl(string);
		free(string);
		string = ft_join(tmp, buffer);
		free(tmp);
	}
	return (return_function(&string, buffer, line, END_LINE));
}

int	gnl_here_doc(int fd, char **line, int free_all)
{
	static t_struct		*buffer_list = NULL;
	t_struct			*tmp;
	int					num;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (ERROR);
	if (free_all == 1 && buffer_list)
	{
		lst_free(&buffer_list, fd);
		return (0);
	}
	tmp = lst_add(&buffer_list, fd);
	num = read_func(fd, tmp->buffer, line);
	if (num == -1 || num == 0)
	{
		lst_free(&buffer_list, fd);
	}
	return (num);
}
