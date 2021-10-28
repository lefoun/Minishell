/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:03:54 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/05 13:49:26 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	sizeof_s1_s2(char const *s1, char const *s2)
{
	int	size;

	size = 0;
	while (*s1)
	{
		size++;
		s1++;
	}
	while (*s2)
	{
		size++;
		s2++;
	}
	return (size);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	char	*joined_str;

	if (!(s1 && s2))
		return (0);
	joined_str = malloc(sizeof(char) * sizeof_s1_s2(s1, s2) + 1);
	if (!joined_str)
		return (0);
	i = 0;
	while (*s1)
	{
		*(joined_str + i) = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		*(joined_str + i) = *s2;
		s2++;
		i++;
	}
	*(joined_str + i) = 0;
	return (joined_str);
}
