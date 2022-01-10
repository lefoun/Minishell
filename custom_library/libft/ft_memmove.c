/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nammari <nammari@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 18:46:50 by nammari           #+#    #+#             */
/*   Updated: 2021/03/23 18:46:53 by nammari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*source;

	source = (unsigned char *)src;
	dest = (unsigned char *)dst;
	if (!dest && !source)
		return (NULL);
	if (len == 0)
		return (dst);
	i = len - 1;
	if (src > dst)
		dst = ft_memcpy(dst, src, len);
	else if (src < dst)
	{
		while (i > 0)
		{
			*(dest + i) = *(source + i);
			--i;
		}
		*(dest + i) = *(source + i);
		return ((void *)dest);
	}
	return (dst);
}
