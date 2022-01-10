/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:50:20 by nammari           #+#    #+#             */
/*   Updated: 2021/07/08 00:06:01 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*tab;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		tab = ft_calloc(1, 1);
		return (tab);
	}
	if (ft_strlen(s) - start <= len)
		len = ft_strlen(s) - start;
	tab = malloc(sizeof(char) * len + 1);
	if (!tab)
		return (NULL);
	while (i < len && s[start])
	{
		tab[i] = s[start];
		++i;
		++start;
	}
	tab[i] = '\0';
	return (tab);
}
