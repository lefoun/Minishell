/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:47:37 by nammari           #+#    #+#             */
/*   Updated: 2021/05/31 15:30:41 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_func(char **tab, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		free(tab[i]);
		++i;
	}
	free(tab);
	return (NULL);
}

static int	is_space(char c, char delimiter)
{
	if (c == delimiter)
		return (1);
	return (0);
}

static int	count_words(char const *str, char c)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && is_space(*str, c))
			++str;
		if (*str && !(is_space(*str, c)))
		{
			++count;
			while (*str && !(is_space(*str, c)))
				++str;
		}
	}
	return (count);
}

static char	*copy_str(char const *str, char c, char **tab, int num)
{
	int		i;
	char	*new_str;

	i = 0;
	while (*str && is_space(*str, c))
		++str;
	while (*str && !(is_space(*str, c)))
	{
		++str;
		++i;
	}
	--str;
	new_str = malloc(sizeof(char) * i + 1);
	if (!new_str)
		return (free_func(tab, num));
	new_str[i] = '\0';
	while (i > 0)
	{
		new_str[i - 1] = *str;
		--str;
		--i;
	}
	return (new_str);
}

char	**ft_split(char const *s, char c)
{
	int		k;
	int		num_words;
	char	**tab;

	if (s == NULL)
		return (NULL);
	k = 0;
	num_words = count_words(s, c);
	tab = malloc(sizeof(char *) * (num_words + 1));
	if (!tab)
		return (NULL);
	while (*s)
	{
		while (*s && is_space(*s, c))
			++s;
		if (*s && (!is_space(*s, c)))
		{
			tab[k] = copy_str(s, c, tab, num_words);
			++k;
			while (*s && (!is_space(*s, c)))
				++s;
		}
	}
	tab[k] = 0;
	return (tab);
}
