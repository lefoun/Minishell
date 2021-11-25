/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 01:02:46 by sdummett          #+#    #+#             */
/*   Updated: 2021/10/04 16:15:53 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup_index(char *str, int index)
{
	char	*duped_str;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	duped_str = malloc(sizeof(*duped_str) * index + 1);
	if (!duped_str)
		return (NULL);
	
	while (i < index)
	{
		duped_str[i] = str[i];
		++i;
	}
	duped_str[i] = '\0';
	return (duped_str);
}
