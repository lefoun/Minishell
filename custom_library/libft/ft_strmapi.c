/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:48:49 by nammari           #+#    #+#             */
/*   Updated: 2021/05/31 19:51:03 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*array;

	i = 0;
	if (!s || !f)
		return (NULL);
	while (s[i])
		++i;
	array = malloc(sizeof(char) * i + 1);
	if (!array)
		return (NULL);
	i = 0;
	while (s[i])
	{
		array[i] = (*f)(i, s[i]);
		++i;
	}
	array[i] = '\0';
	return (array);
}
