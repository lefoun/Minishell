/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stone <stone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 12:03:49 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/10 15:43:55 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1024
# include <fcntl.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		copy_buffer_in_line(char *buffer, char **line);
int		ft_strlen_nl_and_strcpy(char *buffer, char *src, int choice);
int		buffer_handler(char **buffer, char **line, int fd, int eof);
int		cpy_buf_in_l_or_free(char **buffer, char *tmp, int offset, \
		int choice);
char	*save_buffer(char *ptr, char *buffer);
char	*ft_strchr_or_memset(const char *str, int ch, size_t n, int choice);

#endif
