/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:03:40 by nammari           #+#    #+#             */
/*   Updated: 2021/08/30 16:02:11 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include "libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif
# define ERROR -1
# define END_LINE 1
# define END_FILE 0
# define FALSE -1

typedef struct s_struct
{
	int		fd;
	char	buffer[BUFFER_SIZE + 1];
	void	*next;
}			t_struct;

char		*ft_join(char *s1, char *s2);
int			get_next_line(int fd, char **line);
t_struct	*lst_add(t_struct **struct_pointer, int filed);
#endif
