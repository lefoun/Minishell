/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:03:54 by nammari           #+#    #+#             */
/*   Updated: 2021/08/31 14:35:30 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

t_struct	*lst_add(t_struct **struct_pointer, int filed)
{
	t_struct	*new;
	t_struct	*tmp;

	tmp = *struct_pointer;
	while (tmp)
	{
		if (tmp->fd == filed)
			return (tmp);
		tmp = tmp->next;
	}
	new = malloc(sizeof(t_struct));
	if (!new)
		return (NULL);
	new->fd = filed;
	new->next = *(struct_pointer);
	ft_memset(new->buffer, 0, BUFFER_SIZE + 1);
	*(struct_pointer) = new;
	tmp = NULL;
	return (new);
}

char	*ft_join(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*string;

	i = 0;
	j = 0;
	while (s2 && s2[j])
		++j;
	while (s1 && s1[i])
		++i;
	string = malloc(sizeof(char) * (i + j + 1));
	if (!string)
		return (NULL);
	j = -1;
	if (s1)
	{
		i = -1;
		while (s1[++i])
			string[i] = s1[i];
	}
	while (s2 && s2[++j])
		string[i + j] = s2[j];
	string[i + j] = '\0';
	return (string);
}
