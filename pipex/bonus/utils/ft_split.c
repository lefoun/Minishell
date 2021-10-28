/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stone <stone@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 15:52:20 by sdummett          #+#    #+#             */
/*   Updated: 2021/08/10 03:16:49 by stone            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	clearmem(char **strs, int j)
{
	while (j)
	{
		j--;
		free(strs[j]);
	}
	free(strs);
}

static size_t	size_strs(char const *s, char c)
{
	size_t	size;

	if (*s)
	{
		size = 1;
		while ((*s == c) && *s)
			s++;
		while (*s)
		{	
			if (*s == c)
			{
				while (*s && *s == c)
					s++;
				size++;
			}
			else
				s++;
		}
		if (*(s - 1) == c)
			size--;
		return (size);
	}
	else
		return (0);
}

static char const	*splitcpy(char **strs, char const *s, char c, int j)
{
	unsigned int	i;
	unsigned int	len;

	len = 0;
	while (!(s[len] == c) && s[len])
		len++;
	strs[j] = ft_calloc(len + 1, sizeof(char));
	if (!strs[j])
	{
		clearmem(strs, j);
		return (0);
	}
	i = 0;
	while (!(*s == c) && *s)
	{
		strs[j][i] = *s;
		i++;
		s++;
	}
	strs[j][i] = 0;
	return (s);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**strs;

	if (!s)
		return (0);
	strs = malloc((size_strs(s, c) + 1) * sizeof(char *));
	if (!strs)
		return (0);
	j = 0;
	while (*s)
	{
		if (!(*s == c))
		{
			s = splitcpy(strs, s, c, j);
			if (!s)
				return (0);
			j++;
		}
		else
			s++;
	}
	strs[j] = 0;
	return (strs);
}
