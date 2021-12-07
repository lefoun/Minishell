/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:47:51 by nammari           #+#    #+#             */
/*   Updated: 2021/12/07 11:41:09 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*array;

	i = 0;
	if (s1 == NULL)
		return (NULL);
	array = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!array)
		return (NULL);
	while (s1[i])
	{
		array[i] = s1[i];
		++i;
	}
	array[i] = '\0';
	return (array);
}
