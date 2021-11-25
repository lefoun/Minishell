/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rm_n_first_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdummett <sdummett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 20:20:39 by stone             #+#    #+#             */
/*   Updated: 2021/08/05 12:54:11 by sdummett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
		len++;
	return (len);
}

void	rm_n_first_char(char **str, int n)
{
	int		len;
	char	*new;

	if (n <= 0)
		return ;
	len = ft_strlen(*str);
	new = malloc(sizeof(char) * (len + 1));
	len = 0;
	while ((*str)[n] != '\0')
	{
		new[len] = (*str)[n];
		len++;
		n++;
	}
	new[len] = '\0';
	free(*str);
	*str = new;
}
