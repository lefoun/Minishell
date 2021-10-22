/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:44:33 by nammari           #+#    #+#             */
/*   Updated: 2021/05/31 19:50:23 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lenght(int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		++i;
	if (n < 9 && n > -9)
		return (i + 1);
	while (n != 0)
	{
		n = n / 10;
		++i;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int				size;
	char			*array;
	unsigned int	num;

	size = ft_lenght(n);
	num = n;
	array = ft_calloc(sizeof(char), size + 1);
	if (!array)
		return (NULL);
	if (n < 0)
	{
		num = -n;
		array[0] = '-';
	}
	array[size] = '\0';
	while (size-- && array[size] != '-')
	{
		array[size] = (num % 10) + '0';
		num = num / 10;
	}
	return (array);
}
