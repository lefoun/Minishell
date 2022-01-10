/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:48:20 by nammari           #+#    #+#             */
/*   Updated: 2021/03/23 18:48:23 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	size;

	size = 0;
	while (src[size])
		size++;
	if (dstsize == 0)
		return (size);
	i = 0;
	while (dst[i] && i < dstsize)
		++i;
	j = 0;
	while (src[j] && j + i < dstsize - 1)
	{
		dst[i + j] = src[j];
		++j;
	}
	if (i < dstsize)
		dst[i + j] = '\0';
	return (i + size);
}
