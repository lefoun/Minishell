/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_get_next_line_utils_bonus.c               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: noufel <noufel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/11 13:03:54 by nammari           #+#    #+#             */
/*   Updated: 2021/11/25 10:26:36 by noufel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_memset_gnl(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		++i;
	}
}

char	*ft_strdup_gnl(char *str)
{
	int		i;
	char	*string;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i])
		++i;
	string = malloc(sizeof(char) * (i + 1));
	if (!string)
		return (NULL);
	i = 0;
	while (str[i])
	{
		string[i] = str[i];
		++i;
	}
	string[i] = '\0';
	return (string);
}
