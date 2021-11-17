/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:50:09 by nammari           #+#    #+#             */
/*   Updated: 2021/07/08 00:05:46 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	is_present(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		++i;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	char	*tab;
	size_t	j;
	size_t	k;

	i = 0;
	k = 0;
	if (set == NULL || s1 == NULL)
		return (NULL);
	j = ft_strlen(s1);
	while (s1[i] && is_present(s1[i], set))
		++i;
	while (j > 0 && is_present(s1[j - 1], set))
		--j;
	if (j == 0)
		i = 0;
	tab = malloc(sizeof(char) * (j - i + 1));
	if (!tab)
		return (NULL);
	while (i < j)
		tab[k++] = s1[i++];
	tab[k] = '\0';
	return (tab);
}
