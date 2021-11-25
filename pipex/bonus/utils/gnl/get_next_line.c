/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:02:53 by sdummett          #+#    #+#             */
/*   Updated: 2021/07/20 05:49:19 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	cpy_buf_in_l_or_free(char **buffer, char *tmp, int offset, int choice)
{
	int	i;

	if (choice == 1)
	{
		i = 0;
		while ((*buffer)[i] != '\n' && (*buffer)[i] != '\0')
		{
			tmp[offset] = (*buffer)[i];
			offset++;
			i++;
		}
		tmp[offset] = '\0';
		if ((*buffer)[i] == '\n')
			return (1);
		return (0);
	}
	if (choice == 2)
	{
		free(*buffer);
		*buffer = NULL;
		return (offset);
	}
	return (0);
}

int	copy_buffer_in_line(char *buffer, char **line)
{
	int		nl;
	int		offset;
	char	*tmp;

	nl = 0;
	if (*line == NULL)
		offset = ft_strlen_nl_and_strcpy(buffer, NULL, 1);
	else
		offset = ft_strlen_nl_and_strcpy(*line, NULL, 1) + \
				 ft_strlen_nl_and_strcpy(buffer, NULL, 1);
	tmp = (char *)malloc(sizeof(char) * (offset + 1));
	if (!tmp)
		return (-1);
	offset = 0;
	if (*line != NULL)
	{
		ft_strlen_nl_and_strcpy(tmp, *line, 3);
		while (tmp[offset] != '\0')
			offset++;
		free(*line);
	}
	if (cpy_buf_in_l_or_free(&buffer, tmp, offset, 1) == 1)
		nl = 1;
	*line = tmp;
	return (nl);
}

int	buffer_handler(char **buffer, char **line, int fd, int eof)
{
	int	ret;

	while (1)
	{
		ft_strchr_or_memset(*buffer, 0, BUFFER_SIZE + 1, 2);
		ret = read(fd, *buffer, BUFFER_SIZE);
		if (ret == -1)
			return (cpy_buf_in_l_or_free(buffer, NULL, -1, 2));
		if (ret == 0)
		{
			if (eof == 1)
				copy_buffer_in_line(*buffer, line);
			return (cpy_buf_in_l_or_free(buffer, NULL, 0, 2));
		}
		if (copy_buffer_in_line(*buffer, line))
			break ;
		eof = 0;
	}
	*buffer = save_buffer(*buffer, ft_strchr_or_memset(*buffer, \
	'\n', 0, 1) + 1);
	if (line)
		return (1);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*buffer = NULL;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	*line = NULL;
	if (buffer != NULL)
	{
		if (copy_buffer_in_line(buffer, line))
		{
			buffer = save_buffer(buffer, ft_strchr_or_memset(buffer, '\n', \
						0, 1) + 1);
			return (1);
		}
		free(buffer);
	}
	buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buffer)
		return (-1);
	return (buffer_handler(&buffer, line, fd, 1));
}
