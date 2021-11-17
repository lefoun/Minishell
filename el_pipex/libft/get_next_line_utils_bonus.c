/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:03:54 by nammari           #+#    #+#             */
/*   Updated: 2021/07/30 16:01:08 by nammari          ###   ########.fr       */
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
	ft_memset_gnl(new, 0, sizeof(t_struct));
	new->fd = filed;
	new->next = *(struct_pointer);
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

void	ft_memset_gnl(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		++i;
	}
}

char	*ft_strdup_gnl(char *str)
{
	int		i;
	char	*string;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
		++i;
	string = malloc(sizeof(char) * (i + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (str[i])
	{
		string[i] = str[i];
		++i;
	}
	string[i] = '\0';
	return (string);
}
